#include <iomanip>

#include "interpreter.cpp"

using namespace std;

void print_initial_state(unsigned int* const mem) {
    for (int i = 0; i < 65536U; i++) {
        cout << "memory[ " << i << " ] " << "0x" << hex << mem[i] << endl;

        if (mem[i] == 0) {
            break;
        }
    }
}

void print_state(unsigned int* const mem, int* const regs, int* pc) {
    cout << endl;
    cout << "@@@" << endl;
    cout << "state" << endl;
    cout << "\tpc " << *pc << endl;
    cout << "\tmemory:" << endl;

    for (int i = 0; i < 65536U; i++) {
        cout << "\t\tmemory[ " << i << " ] " << "0x" << hex << mem[i] << endl;

        if (mem[i] == 0) {
            break;
        }
    }

    cout << "\tregisters:" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "\t\treg[ " << i << " ] " << "0x" << hex << regs[i] << endl;
    }

    cout << "end state" << endl;
}

void simulate(unsigned int* const mem, int* const regs) {
    int pc = 0;
    int safe_break_counter = 0;
    int safe_break_ceil = 20;

    print_initial_state(mem);
    
    while (pc != -1 && safe_break_counter < safe_break_ceil) {
        print_state(mem, regs, &pc);

        interpret(mem, regs, &pc);

        regs[0] = 0;

        safe_break_counter += 1;
    }

    cout << "halted" << endl;
    cout << "total of " << safe_break_counter << " instructions executed" << endl;
    cout << "final state of machine: " << endl;

    print_state(mem, regs, &pc);
}