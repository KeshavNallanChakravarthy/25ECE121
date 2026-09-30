#include <iostream>
#include <cmath>

double volume(double side) {
    return side * side * side;
}

double volume(double length, double width, double height) {
    return length * width * height;
}


double volume(double radius, double height) {
    return M_PI * radius * radius * height;
}

int main() {
    std::cout << "Cube volume (side=3): " << volume(3.0) << std::endl;
    std::cout << "Cuboid volume (3x4x5): " << volume(3.0, 4.0, 5.0) << std::endl;
    std::cout << "Cylinder volume (r=3, h=5): " << volume(3.0, 5.0) << std::endl;
    return 0;
}
