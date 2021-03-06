#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day14.h>
#include <vector>
#include <bitset>
#include <regex>
#include <numeric>
#include <ranges>
namespace aocmaxnoe2020 { namespace day14 {


uint64_t Memory::sum() {
    auto add_values = [](uint64_t value, const auto& p) {return value + p.second;};
    return std::accumulate(fields.cbegin(), fields.cend(), 0ull, add_values);
}


void StaticMemory::set(size_t address, uint64_t value, const Mask& mask) {
    value &= (~mask.mask_zero);
    value |= mask.mask_one;
    fields[address] = value;
}

void FloatingMemory::set(size_t address, uint64_t value, const Mask& mask) {
    address |= mask.mask_one;

    std::vector<uint64_t> addresses;

    std::bitset<N_BITS> floating_bits{mask.mask_floating};
    size_t n_adresses = 1ull << floating_bits.count();

    addresses.reserve(n_adresses);
    addresses.push_back(address);

    for (size_t bit = 0; bit < floating_bits.size(); bit++) {
        if (!floating_bits[bit]) continue;

        size_t current_size  = addresses.size();
        for (size_t i = 0; i < current_size; i++) {
            addresses.push_back(addresses.at(i) ^ (1ull << bit));
        }
    }

    for (uint64_t address: addresses) {
        fields[address] = value;
    }

}

void SetMem::execute(Memory& mem, Mask& mask) {
    mem.set(address, value, mask);
}

void SetMask::execute(Memory&, Mask& m) {
    m = mask;
}


instructions_t parse_input(std::string_view input) {
    std::regex mem_re{R"(mem\[(\d+)\] = (\d+))"};
    instructions_t instructions;
    auto lines = split_lines(input);
    instructions.reserve(lines.size());

    for (auto line: lines) {
        if (line.starts_with("mask = ")) {
            instructions.push_back(SetMask::fromString(line.substr(7, line.size())));
        } else {
            std::smatch match;
            std::string line_str{line};

            if (!std::regex_match(line_str, match, mem_re)) {
                throw std::runtime_error("Regex did not match: '" + line_str + "'");
            }

            size_t addr = std::stoull(match[1]);
            size_t value = std::stoull(match[2]);
            instructions.push_back(std::make_unique<SetMem>(addr, value));
        }
    }
    return instructions;
}


uint64_t Program::execute() {
    if (mem == nullptr) throw std::runtime_error("Uninitialized memory");

    for (const auto& instruction: instructions) {
        instruction->execute(*mem, mask);
    }

    return mem->sum();

}


uint64_t part1(const instructions_t& instructions) {
    Program program{
        .mem = std::make_unique<StaticMemory>(),
        .instructions = instructions,
    };
    return program.execute();
}

uint64_t part2(const instructions_t& instructions) {
    Program program{
        .mem = std::make_unique<FloatingMemory>(),
        .instructions = instructions,
    };
    return program.execute();
}

}}
