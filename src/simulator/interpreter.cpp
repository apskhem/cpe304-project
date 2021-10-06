#include <stdexcept>
#include <sstream>

#include "instruction.cpp"

using namespace std;

string interpret(unsigned int* const mem, int* const regs, int* pc, bool* is_halted) {
    stringstream ss;
    unsigned int bin_instr = mem[*pc];
    Instruction instr(bin_instr);

    switch (instr.opcode()) {
        // add (R-type)
        case 0b000: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int rd = instr.rd();
            int rs1_val = regs[rs1];
            int rs2_val = regs[rs2];

            regs[rd] = rs1_val + rs2_val;

            ss
            << "--" << endl
            << "nextexec: " << "add @ " << "rs1: " << rs1 << ", rs2: " << rs2 << ", rd: " << rd
            << ", rs1_val: " << rs1_val << ", rs2_val: " << rs2_val << ", result: " << regs[rd] << endl
            << "--" << endl;

            *pc = *pc + 1;
            break;
        }
        // nand (R-type)
        case 0b001: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int rd = instr.rd();
            int rs1_val = regs[rs1];
            int rs2_val = regs[rs2];

            regs[rd] = ~(rs1_val & rs2_val);

            ss
            << "--" << endl
            << "nextexec: " << "nand @ " << "rs1: " << rs1 << ", rs2: " << rs2 << ", rd: " << rd
            << ", rs1_val: " << rs1_val << ", rs2_val: " << rs2_val << ", result: " << regs[rd] << endl
            << "--" << endl;

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

            ss
            << "--" << endl
            << "nextexec: " << "lw @ " << "rs1: " << rs1 << ", rs2: " << rs2 << ", offset: " << offset
            << ", rs1_val: " << rs1_val << ", written_val: " << regs[rs2] << endl
            << "--" << endl;

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

            ss
            << "--" << endl
            << "nextexec: " << "sw @ " << "rs1: " << rs1 << ", rs2: " << rs2 << ", offset: " << offset
            << ", rs1_val: " << rs1_val << ", written_val: " << regs[rs2] << endl
            << "--" << endl;

            *pc = *pc + 1;
            break;
        }
        // beq (I-type)
        case 0b100: {
            int rs1 = instr.rs1();
            int rs2 = instr.rs2();
            int offset = instr.offset();
            int rs1_val = regs[rs1];
            int rs2_val = regs[rs2];

            *pc = *pc + 1;

            if (rs1_val == rs2_val) {
                *pc = *pc + offset;
            }

            ss
            << "--" << endl
            << "nextexec: " << "beq @ " << "rs1: " << rs1 << ", rs2: " << rs2 << ", offset: " << offset
            << ", rs1_val: " << rs1_val << ", rs2_val: " << rs2_val << ", is_jumped: " << (rs1_val == rs2_val ? "true" : "false") << endl
            << "--" << endl;

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

            ss
            << "--" << endl
            << "nextexec: " << "jalr @ " << "rs1: " << rs1 << ", rs2: " << rs2
            << ", return address: " << regs[rs2] << ", destination: " << rs1_val << endl
            << "--" << endl;

            break;
        }
        // halt (O-type)
        case 0b110: {
            *is_halted = true;

            *pc = *pc + 1;
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

    cout << ss.str();

    return ss.str();
}