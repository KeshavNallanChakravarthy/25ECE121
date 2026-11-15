// 2. Multilevel shapes hierarchy[cite: 2]
class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {
        std::cout << "  -> Shape constructor called (color: " << color << ")\n";
    }
    virtual ~Shape() {}
};

// Polygon inherits from Shape and adds numSides[cite: 2]
class Polygon : public Shape {
protected:
    int numSides;

public:
    Polygon(std::string c, int sides) : Shape(c), numSides(sides) {
        std::cout << "  -> Polygon constructor called (sides: " << numSides << ")\n";
    }
};

// Rectangle inherits from Polygon and adds area (or another field)[cite: 2]
class Rectangle : public Polygon {
private:
    double area;

public:
    Rectangle(std::string c, int sides, double a) : Polygon(c, sides), area(a) {
        std::cout << "  -> Rectangle constructor called (area: " << area << ")\n";
    }
};
