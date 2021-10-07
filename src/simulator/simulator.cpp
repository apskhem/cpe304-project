#include <iostream>
#include <sstream>
#include <fstream>

#include "interpreter.cpp"

using namespace std;

string result_log = "";

void collect_result(string s) {
    result_log += s;
}

void create_log_file() {
    ofstream out("result_log.txt", fstream::out);
    out << result_log;
	out.close();
}

void print_mem_state(unsigned int* const mem) {
    stringstream ss;
    for (int i = 0; i < 65536U && (mem[i] || mem[i + 1]); i++) {
        ss << "memory[ " << i << " ] " << (int) mem[i] << endl;
    }
    
    cout << ss.str();
    collect_result(ss.str());
}

void print_state(unsigned int* const mem, int* const regs, int* pc) {
    stringstream ss;

    ss << endl;
    ss << "@@@" << endl;
    ss << "state" << endl;
    ss << "\tpc " << *pc << endl;
    ss << "\tmemory:" << endl;

    for (int i = 0; i < 65536U && (mem[i] || mem[i + 1]); i++) {
        ss << "\t\tmemory[ " << i << " ] " << (int) mem[i] << endl;
    }

    ss << "\tregisters:" << endl;

    for (int i = 0; i < 8; i++) {
        ss << "\t\treg[ " << i << " ] " << (int) regs[i] << endl;
    }

    ss << "end state" << endl;

    cout << ss.str();
    collect_result(ss.str());
}

void print_final_state(unsigned int* const mem, int* const regs, int* pc, int counter) {
    stringstream ss;

    ss << "halted" << endl;
    ss << "total of " << counter << " instructions executed" << endl;
    ss << "final state of machine: " << endl;

    cout << ss.str();
    collect_result(ss.str());

    print_state(mem, regs, pc);
}

void simulate(unsigned int* const mem, int* const regs) {
    bool is_halted = false;
    int pc = 0;
    int safe_break_counter = 0;
    int safe_break_ceil = 20000;

    print_mem_state(mem);
    
    while (!is_halted && safe_break_counter < safe_break_ceil) {
        print_state(mem, regs, &pc);

        string s = interpret(mem, regs, &pc, &is_halted);

        collect_result(s);

        regs[0] = 0;

        safe_break_counter += 1;
    }

    print_final_state(mem, regs, &pc, safe_break_counter);
    
    // create log file
    create_log_file();
}