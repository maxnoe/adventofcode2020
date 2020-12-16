#ifndef day14_H
#define day14_H

#include <aocmaxnoe2020/aocmaxnoe2020.h>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <utility>
#include <memory>


namespace aocmaxnoe2020 { namespace day14 {

const int N_BITS = 36;


struct Mask {
    uint64_t mask_zero = 0;
    uint64_t mask_one = 0;
    uint64_t mask_x = 0;
};


struct Memory {
    virtual void set(size_t address, uint64_t value, const Mask& mask) = 0;
    uint64_t sum();
    std::unordered_map<size_t, uint64_t> fields;
};

struct StaticMemory : public Memory {
    virtual void set(size_t address, uint64_t value, const Mask& mask) override;
};

struct FloatingMemory : public Memory {
    virtual void set(size_t address, uint64_t value, const Mask& mask) override;
};

struct Instruction {
    virtual void execute(Memory& mem, Mask& mask) = 0;
};

using instructions_t = std::vector<std::shared_ptr<Instruction>>;

struct Program {
    Mask mask = Mask{};
    std::unique_ptr<Memory> mem;
    instructions_t instructions;
    uint64_t execute();
};


struct SetMask: public Instruction {
    virtual void execute(Memory& mem, Mask& mask) override;

    const Mask mask;
    SetMask(Mask mask) : mask(mask) {}

    static std::unique_ptr<SetMask> fromString(std::string_view s) {
        if (s.size() != N_BITS) throw std::runtime_error("Wrong number of bits");

        uint64_t mask_zero = 0;
        uint64_t mask_one = 0;
        uint64_t mask_x = 0;

        for (size_t i = 0; i < s.size(); i++) {
            uint64_t bit = 1ull << (N_BITS - i - 1);
            switch (s.at(i)) {
                case '0': mask_zero |= bit; break;
                case '1': mask_one |= bit; break;
                case 'X': mask_x |= bit; break;
                default:
                    throw std::runtime_error("Unexpected char '" + std::string{s.at(1)});
            }
        }
        return std::make_unique<SetMask>(Mask{mask_zero, mask_one, mask_x});
    }
};

struct SetMem: public Instruction {
    virtual void execute(Memory& mem, Mask& mask) override;

    const size_t address = 0;
    const uint64_t value = 0;

    SetMem(size_t address, uint64_t value) : address(address), value(value){}
};



instructions_t parse_input(std::string_view input);
uint64_t part1(const instructions_t& instructions);
uint64_t part2(const instructions_t& instructions);

}}


#endif /* ifndef day14_H */
