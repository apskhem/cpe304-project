using namespace std;

unsigned int compress_binary(char ch1, char ch2, char ch3, char ch4) {
    unsigned int a = ch1 << 12;
    unsigned int b = ch2 << 8;
    unsigned int c = ch3 << 4;
    unsigned int d = ch4 << 0;

    return a + b + c + d;
}

void parse_buffer(unsigned int* mem, char* raw, int file_size) {
    for (int i = 0; i < file_size; i += 4) {
        char ch1 = *(raw + i + 0);
        char ch2 = *(raw + i + 1);
        char ch3 = *(raw + i + 2);
        char ch4 = *(raw + i + 3);

        mem[i / 4] = compress_binary(ch1, ch2, ch3, ch4);

        cout << mem[i / 4] << endl;
    }
}

unsigned int parse_instr_type(unsigned int bin_instr) {
    return bin_instr >> 22;
}