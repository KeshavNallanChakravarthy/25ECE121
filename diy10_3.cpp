#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Student {
public:
    std::string name;
    double marks;

    Student() : name(""), marks(0.0) {}
    Student(std::string n, double m) : name(n), marks(m) {}
};

void processStudentRecords() {
    // 1. Store sample name and marks pairs into a file[cite: 5]
    std::ofstream dataOut("students.txt");
    if (dataOut) {
        dataOut << "Alice 88.5\n";
        dataOut << "Bob 94.0\n";
        dataOut << "Charlie 79.5\n";
        dataOut << "Diana 91.0\n";
        dataOut.close();
    }

    // 2. Read records back into an array/vector of Student objects[cite: 5]
    std::ifstream dataIn("students.txt");
    if (!dataIn) {
        std::cerr << "Error: Could not open students.txt[cite: 5].\n";
        return;
    }

    std::vector<Student> students;
    std::string name;
    double marks;
    while (dataIn >> name >> marks) {
        students.emplace_back(name, marks);
    }
    dataIn.close();

    if (students.empty()) {
        std::cout << "No student records found[cite: 5].\n";
        return;
    }

    // 3. Find and print the topper[cite: 5]
    const Student* topper = &students[0];
    for (size_t i = 1; i < students.size(); ++i) {
        if (students[i].marks > topper->marks) {
            topper = &students[i];
        }
    }

    std::cout << "=== 3. Records into Objects ===\n";
    std::cout << "Topper: " << topper->name << " with " << topper->marks << " marks[cite: 5].\n";
}
