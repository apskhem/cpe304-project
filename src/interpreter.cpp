#include <stdexcept>

#include "instruction.cpp"

using namespace std;

void interpret(unsigned int* const mem, int* const regs, int* pc) {
    unsigned int bin_instr = mem[*pc];
    Instruction instr(bin_instr);

    switch (instr.opcode()) {
        // add (R-type)
        case 0b000: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int rd = instr.rd();

            regs[rd] = rs1 + rs2;

            *pc = *pc + 1;
            break;
        }
        // nand (R-type)
        case 0b001: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int rd = instr.rd();

            regs[rd] = ~(rs1 & rs2);

            *pc = *pc + 1;
            break;
        }
        // lw (I-type)
        case 0b010: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int offset = instr.offset();
            int rs1_val = regs[rs1];
            
            regs[rs2] = mem[rs1_val + offset];

            *pc = *pc + 1;
            break;
        }
        // sw (I-type)
        case 0b011: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int offset = instr.offset();
            int rs1_val = regs[rs1];

            mem[rs1_val + offset] = regs[rs2];

            *pc = *pc + 1;
            break;
        }
        // beg (I-type)
        case 0b100: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int offset = instr.offset();
            int rs1_val = regs[rs1];
            int rs2_val = regs[rs2];

            if (rs1_val == rs2_val) {
                *pc = *pc + 1;
            }
            else {
                *pc = *pc + offset;
            }

            break;
        }
        // jalr (J-type)
        case 0b101: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int rs1_val = regs[rs1];
            
            // store pc + 1
            regs[rs2] = *pc + 1;

            // perform jump
            *pc = rs1_val;

            break;
        }
        // halt (O-type)
        case 0b110: {
            *pc = -1;
            break;
        }
        // noop (O-type)
        case 0b111: {
            *pc = *pc + 1;
            break;
        }
        default: {
            throw runtime_error("Error: unknown instruction opcode.");
        }
    }
}