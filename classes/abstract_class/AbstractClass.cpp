// This program demonstrates the use of a class interface in C++.
// An interface is a class that contains only pure virtual functions.
// It defines a contract that any derived class must follow by implementing all
// of the pure virtual functions.

#include <iostream>

// The 'Shape' class acts as an interface.
// It has a pure virtual function `calculateArea()`, which is indicated by '= 0'.
// A class with at least one pure virtual function is an abstract class and
// cannot be instantiated directly.
class Shape {
public:
    // This is a pure virtual function. Any class that inherits from Shape
    // MUST provide an implementation for this function.
    virtual double calculateArea() const = 0;

    // A virtual destructor is good practice for base classes to ensure
    // proper cleanup of derived class objects when deleted through a base class pointer.
    virtual ~Shape() {}
};

// The 'Circle' class inherits from the 'Shape' interface.
// It must implement the `calculateArea()` method to be a concrete class.
class Circle : public Shape {
private:
    double radius;
public:
    // Constructor to initialize the radius.
    Circle(double r) : radius(r) {}

    // Implementation of the pure virtual function from the base class.
    // The 'override' keyword is a good practice to ensure we are actually
    // overriding a virtual function.
    double calculateArea() const override {
        // Area of a circle is PI * r^2
        return 3.14159 * radius * radius;
    }
};

// The 'Rectangle' class also inherits from the 'Shape' interface.
// It provides its own implementation of `calculateArea()`.
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    // Constructor to initialize width and height.
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementation of the pure virtual function.
    double calculateArea() const override {
        // Area of a rectangle is width * height
        return width * height;
    }
};

int main() {
    // We cannot create an object of the abstract base class 'Shape'.
    // Shape myShape; // This would result in a compilation error.

    // We can, however, use pointers to the base class to point to objects
    // of the derived, concrete classes. This demonstrates polymorphism.
    Shape* myCircle = new Circle(5.0);
    Shape* myRectangle = new Rectangle(4.0, 6.0);

    // Call the `calculateArea()` function on the objects through the base class pointers.
    // The correct implementation (Circle or Rectangle) is called at runtime.
    std::cout << "The area of the circle is: " << myCircle->calculateArea() << std::endl;
    std::cout << "The area of the rectangle is: " << myRectangle->calculateArea() << std::endl;

    // Clean up dynamically allocated memory.
    delete myCircle;
    delete myRectangle;

    return 0;
}