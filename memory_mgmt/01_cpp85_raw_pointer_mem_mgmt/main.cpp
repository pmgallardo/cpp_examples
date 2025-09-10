#include <iostream>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "MyClass constructed with value: " << value << std::endl;
    }
    
    ~MyClass() {
        std::cout << "MyClass destroyed with value: " << data << std::endl;
    }
    
    void print() const {
        std::cout << "Value: " << data << std::endl;
    }
    
private:
    int data;
};

int main() {
    // Manual memory management with raw pointers
    MyClass* ptr1 = new MyClass(42); // Allocation
    ptr1->print();
    
    MyClass* ptr2 = new MyClass(100); // Another allocation
    ptr2->print();
    
    // Must remember to delete!
    delete ptr1; // Manual deallocation
    delete ptr2; // Manual deallocation
    
    // Forgetting to delete causes memory leaks
    // MyClass* leaked = new MyClass(999); // This would leak if not deleted
    
    return 0;
}