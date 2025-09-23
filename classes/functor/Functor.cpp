#include <iostream>
using namespace std;

// A function object (functor)
class Square {
public:
    // Overload operator()
    int operator()(int x) const {
        return x * x;
    }
};

int main() {
    Square square;       // Create a function object
    cout << square(5) << endl;   // Calls operator(), prints 25
    cout << square(10) << endl;  // Prints 100

    return 0;
}