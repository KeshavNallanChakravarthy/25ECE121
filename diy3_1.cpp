#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    
    Rectangle(double l = 1.0, double w = 1.0) {
        // initalize 
        length = 1.0;
        width = 1.0;
        
        setLength(l);
        setWidth(w);
    }

    // Setter 
    void setLength(double l) {
        if (l < 0) {
            std::cerr << "Error: Length cannot be negative. Value unchanged.\n";
            return; // Exit 
        }
        length = l;
    }

    // Setter 
    void setWidth(double w) {
        if (w < 0) {
            std::cerr << "Error: Width cannot be negative. Value unchanged.\n";
            return; 
        }
        width = w;
    }

    // Get dimensions 
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Computations
    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
   
    Rectangle rect(5.0, 4.0);
    std::cout << "Initial Dimensions -> Length: " << rect.getLength() << ", Width: " << rect.getWidth() << "\n";
    std::cout << "Area: " << rect.area() << " | Perimeter: " << rect.perimeter() << "\n\n";

    
    std::cout << "Attempting to change width to -3.0...\n";
    rect.setWidth(-3.0); 

    
    std::cout << "\nCurrent Dimensions -> Length: " << rect.getLength() << ", Width: " << rect.getWidth() << "\n";
    
    return 0;
}
