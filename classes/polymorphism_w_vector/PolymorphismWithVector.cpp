#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal sound\n";
    }
    virtual ~Animal() = default; // Important for deleting via base pointer
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals; // store polymorphic objects

    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& a : animals) {
        a->speak();  // Polymorphism works correctly
    }
}
