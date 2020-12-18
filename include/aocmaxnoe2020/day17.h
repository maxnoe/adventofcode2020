#ifndef day17_H
#define day17_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <unordered_set>
#include <array>
#include <string_view>
#include <iostream>
#include <absl/hash/hash.h>


namespace aocmaxnoe2020 { namespace day17 {


struct Point3D {
    int x = 0;
    int y = 0;
    int z = 0;

    using Set = std::unordered_set<Point3D, absl::Hash<Point3D>>;
    const static size_t N_NEIGHBORS = 26;

    template <typename H>
    friend H AbslHashValue(H h, const Point3D& p) {
        return H::combine(std::move(h), p.x, p.y, p.z);
    }

    Set get_neighbors() const {
        Set neighbors;
        neighbors.reserve(N_NEIGHBORS);

        for (int dx = -1; dx <= 1; dx ++) {
            for (int dy = -1; dy <= 1; dy ++) {
                for (int dz = -1; dz <= 1; dz ++) {
                    neighbors.emplace(x + dx, y + dy, z + dz);
                }
            }
        }

        neighbors.erase(Point3D{x, y, z});
        return neighbors;
    }
};

bool operator== (const Point3D& lhs, const Point3D& rhs);


struct Point4D {
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;

    using Set = std::unordered_set<Point4D, absl::Hash<Point4D>>;
    const static size_t N_NEIGHBORS = 80;

    template <typename H>
    friend H AbslHashValue(H h, const Point4D& p) {
        return H::combine(std::move(h), p.x, p.y, p.z, p.w);
    }

    Set get_neighbors() const {
        Set neighbors;
        neighbors.reserve(N_NEIGHBORS);

        for (int dx = -1; dx <= 1; dx ++) {
            for (int dy = -1; dy <= 1; dy ++) {
                for (int dz = -1; dz <= 1; dz ++) {
                    for (int dw = -1; dw <= 1; dw ++) {
                        neighbors.emplace(x + dx, y + dy, z + dz, w + dw);
                    }
                }
            }
        }

        neighbors.erase(Point4D{x, y, z, w});
        return neighbors;
    }
};

bool operator== (const Point4D& lhs, const Point4D& rhs);


template<class Point>
class GoL {
    typename Point::Set current;
    typename Point::Set next;

    public:
        GoL(typename Point::Set state) : current(state) {}
        void do_step();
        size_t living_neighbors(const Point& p);
        size_t living_cells();
};


Point3D::Set parse_input(std::string_view input);
uint64_t part1(const Point3D::Set& input);
uint64_t part2(const Point3D::Set& input);

}}


#endif /* ifndef day17_H */
