using namespace std;

class Instruction {
private:
    unsigned int raw;

public:
    Instruction(unsigned int bin_instr) {
        (*this).raw = bin_instr;
    }

    unsigned int opcode() {
        return (*this).raw >> 22;
    }

    unsigned int rs1() {
        return 0;
    }

    unsigned int rs2() {
        return 0;
    }

    unsigned int rd() {
        return 0;
    }

    short offset() {
        return (short) (*this).raw;
    }
};