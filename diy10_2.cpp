#include <iostream>
#include <fstream>
#include <string>

void lineNumberedCopy() {
    std::ifstream infile("in.txt");
    if (!infile) {
        std::cerr << "Error: Could not open in.txt for reading[cite: 5].\n";
        return;
    }

    std::ofstream outfile("out.txt");
    if (!outfile) {
        std::cerr << "Error: Could not open out.txt for writing[cite: 5].\n";
        return;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(infile, line)) {
        outfile << lineNumber++ << ": " << line << "\n";
    }

    infile.close();
    outfile.close();
    std::cout << "=== 2. Line-Numbered Copy ===\n";
    std::cout << "Successfully copied and numbered lines from in.txt to out.txt[cite: 5].\n";
}
