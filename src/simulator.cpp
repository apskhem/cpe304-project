#include "interpreter.cpp"

using namespace std;

void simulate(unsigned int* const mem, int* const regs) {
    unsigned int pc = 0;
    bool is_continued = true;
    
    while (is_continued) {
        is_continued = interpret(mem, regs, &pc);
    }
}