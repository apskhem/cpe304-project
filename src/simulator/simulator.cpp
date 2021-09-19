#include <iostream>

#include "interpreter.cpp"

using namespace std;

void print_mem_state(unsigned int* const mem) {
    for (int i = 0; i < 65536U && mem[i]; i++) {
        cout << "memory[ " << i << " ] " << mem[i] << endl;
    }
}

void print_state(unsigned int* const mem, int* const regs, int* pc) {
    cout << endl;
    cout << "@@@" << endl;
    cout << "state" << endl;
    cout << "\tpc " << *pc << endl;
    cout << "\tmemory:" << endl;

    for (int i = 0; i < 65536U && mem[i]; i++) {
        cout << "\t\tmemory[ " << i << " ] " << mem[i] << endl;
    }

    cout << "\tregisters:" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "\t\treg[ " << i << " ] " << regs[i] << endl;
    }

    cout << "end state" << endl;
}

void print_final_state(unsigned int* const mem, int* const regs, int* pc, int counter) {
    cout << "halted" << endl;
    cout << "total of " << counter << " instructions executed" << endl;
    cout << "final state of machine: " << endl;

    print_state(mem, regs, pc);
}

void simulate(unsigned int* const mem, int* const regs) {
    int pc = 0;
    int safe_break_counter = 0;
    int safe_break_ceil = 1000;

    print_mem_state(mem);
    
    while (pc != -1 && safe_break_counter < safe_break_ceil) {
        print_state(mem, regs, &pc);

        interpret(mem, regs, &pc);

        regs[0] = 0;

        safe_break_counter += 1;
    }

    print_final_state(mem, regs, &pc, safe_break_counter);
}