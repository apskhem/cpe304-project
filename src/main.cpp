#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string text_line;
    ifstream in_file("test/filename.txt");

    while (getline(in_file, text_line)) {
        // Output the text from the file
        cout << text_line << endl;
    }

    in_file.close();
}