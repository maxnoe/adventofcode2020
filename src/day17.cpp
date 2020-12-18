#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day17.h>


namespace aocmaxnoe2020 { namespace day17 {

bool operator== (const Point3D& lhs, const Point3D& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}

bool operator== (const Point4D& lhs, const Point4D& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
}

Point3D operator+ (const Point3D& lhs, const Point3D& rhs) {
    return Point3D{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

Point3D::Set parse_input(std::string_view s) {
    Point3D::Set state;
    int z = 0;
    
    auto lines = split_lines(s);

    for (size_t y = 0; y < lines.size(); y++) {
        auto line = lines.at(y);

        for (size_t x = 0; x < line.size(); x++) {
            if (line.at(x) == '#') {
                state.emplace(x, -y, z);
            }
        }
    }
    return state;
}


template<class Point>
void GoL<Point>::do_step() {
    typename Point::Set checked;
    for (const auto& p: current) {
        checked.insert(p);

        // update living cells
        size_t neighbors = living_neighbors(p);
        if (neighbors == 2 || neighbors == 3) {
            next.insert(p);
        }

        for (const auto& neighbor: p.get_neighbors()) {
            if (checked.contains(neighbor)) continue;

            size_t neighbors = living_neighbors(neighbor);
            if (neighbors == 3) {
                next.insert(neighbor);
            }
            checked.insert(neighbor);
        }
    } 
    
    current = next;
    next.clear();
}

template<class Point>
size_t GoL<Point>::living_neighbors(const Point &p) {
    auto neighbor_lives = [this](const auto& neighbor) {
        return current.contains(neighbor);
    };
    return std::ranges::count_if(p.get_neighbors(), neighbor_lives);
}

template<class Point>
size_t GoL<Point>::living_cells() {
    return current.size();
}

uint64_t part1(const Point3D::Set& state) {
    GoL<Point3D> game{state};

    for (int i = 0; i < 6; ++i) {
        game.do_step();
    }

    return game.living_cells();
}

uint64_t part2(const Point3D::Set& state) {
    Point4D::Set state4D;
    state4D.reserve(state.size());
    for (const auto& p: state) {
        state4D.emplace(p.x, p.y, p.z, 0);
    }

    GoL<Point4D> game{state4D};

    for (int i = 0; i < 6; ++i) {
        game.do_step();
    }

    return game.living_cells();
}


}}
