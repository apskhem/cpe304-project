#include <stdexcept>

#include "instruction.cpp"

using namespace std;

void interpret(unsigned int* const mem, int* const regs, int* cp) {
    unsigned int bin_instr = mem[*cp];
    Instruction instr(bin_instr);

    switch (instr.opcode()) {
        // add (R-type)
        case 0b000: {
            *cp = *cp + 1;
            break;
        }
        // nand (R-type)
        case 0b001: {
            *cp = *cp + 1;
            break;
        }
        // lw (I-type)
        case 0b010: {
            *cp = *cp + 1;
            break;
        }
        // sw (I-type)
        case 0b011: {
            *cp = *cp + 1;
            break;
        }
        // beg (I-type)
        case 0b100: {
            break;
        }
        // jalr (J-type)
        case 0b101: {
            break;
        }
        // halt (O-type)
        case 0b110: {
            *cp = -1;
            break;
        }
        // noop (O-type)
        case 0b111: {
            *cp = *cp + 1;
            break;
        }
        default: {
            throw runtime_error("Error: unknown instruction opcode.");
        }
    }
}