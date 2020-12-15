#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <aocmaxnoe2020/day14.h>
#include <vector>
#include <bitset>
#include <regex>
#include <numeric>

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

void SetMem::execute(Memory& mem, Mask& mask) {
    mem.set(address, value, mask);
}

void SetMask::execute(Memory&, Mask& mask) {
    mask.mask_zero = this->mask.mask_zero;
    mask.mask_one = this->mask.mask_one;
    mask.mask_x = this->mask.mask_x;
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
    /* Program program{ */
    /*     .mem = std::make_unique<StaticMemory>(), */
    /*     .instructions = instructions, */
    /* }; */
    /* return program.execute(); */
    return 0;
}

}}
