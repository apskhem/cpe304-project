#include "interpreter.cpp"

using namespace std;

void simulate(unsigned int* const mem, int* const regs) {
    int pc = 0;
    
    while (pc != -1) {
        interpret(mem, regs, &pc);

        regs[0] = 0;
    }
}