using namespace std;

class Instruction {
private:
    unsigned int raw;

public:
    Instruction(unsigned int bin_instr) {
        (*this).raw = bin_instr;
    }

    unsigned int opcode() {
        return (*this).get_bin_range(24, 22);
    }

    unsigned int rs1() {
        return (*this).get_bin_range(21, 19);
    }

    unsigned int rs2() {
        return (*this).get_bin_range(18, 16);
    }

    unsigned int rd() {
        return (*this).get_bin_range(2, 0);
    }

    short offset() {
        return (short) (*this).raw;
    }

private:
    int get_bin_range(int start, int end) {
        int sll = 32 - (start + 1);
        int srll = sll + end;

        int res = ((*this).raw << sll) >> srll;

        return res;
    }
};