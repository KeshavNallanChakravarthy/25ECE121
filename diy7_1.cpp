#include <iostream>
#include <string>

// 1. Base Employee class
class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    virtual void printDetails() const {
        std::cout << "Employee ID: " << id << ", Name: " << name << std::endl;
    }

    virtual ~Employee() {}
};

// Derived Manager class adds team size
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(std::string n, int i, int ts) : Employee(n, i), teamSize(ts) {}

    void printDetails() const override {
        std::cout << "Manager ID: " << id << ", Name: " << name 
                  << ", Team Size: " << teamSize << std::endl;
    }
};

// Derived Engineer class adds skill[cite: 2]
class Engineer : public Employee {
private:
    std::string skill;

public:
    Engineer(std::string n, int i, std::string s) : Employee(n, i), skill(s) {}

    void printDetails() const override {
        std::cout << "Engineer ID: " << id << ", Name: " << name 
                  << ", Skill: " << skill << std::endl;
    }
};
