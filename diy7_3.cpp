// 3. Diamond inheritance using virtual base[cite: 2]
class Person {
protected:
    std::string name;

public:
    Person(std::string n) : name(n) {
        std::cout << "    -> Person constructor called for: " << name << "\n";
    }
    virtual ~Person() {}
};

// Virtual base inheritance for Student[cite: 2]
class Student : virtual public Person {
public:
    Student(std::string n) : Person(n) {
        std::cout << "    -> Student constructor called.\n";
    }
};

// Virtual base inheritance for Staff (representing Employee branch)[cite: 2]
class Staff : virtual public Person {
public:
    Staff(std::string n) : Person(n) {
        std::cout << "    -> Staff (Employee branch) constructor called.\n";
    }
};

// TA (Teaching Assistant) inherits from both Student and Staff[cite: 2]
class TA : public Student, public Staff {
public:
    // In virtual inheritance, the most derived class (TA) initializes the virtual base (Person)
    TA(std::string n) : Person(n), Student(n), Staff(n) {
        std::cout << "    -> TA constructor called for: " << name << "\n";
    }
};
