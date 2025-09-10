#include <iostream>
#include <memory> // For smart pointers

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "MyClass constructed with value: " << value << std::endl;
    }
    
    // destructor declaration
    ~MyClass() {
        // This function is called automatically when this code is executed:
        // delete class_instance_pointer;
        
        
        std::cout << "MyClass destroyed with value: " << data << std::endl;
    }
    
    void print() const {
        std::cout << "Value: " << data << std::endl;
    }
    
private:
    int data;
};

int main() {
    // Smart pointers type are: unique_ptr, shared_ptr and weak_ptr

    // Unique pointer - exclusive ownership
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(42);
    ptr1->print();
    
    // Shared pointer - shared ownership
    std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>(100);
    {
        std::shared_ptr<MyClass> ptr3 = ptr2; // Both point to same object
        ptr3->print();
    } // ptr3 goes out of scope, but object persists because ptr2 still owns it
    
    ptr2->print();
    
    // Weak pointer - non-owning reference
    std::weak_ptr<MyClass> weakPtr = ptr2;
    
    if (auto sharedPtr = weakPtr.lock()) {
        sharedPtr->print();
    }
    
    return 0;
    // All objects automatically destroyed here
    //
    // It calls automatically:
    // delete class_instance_pointer;
}