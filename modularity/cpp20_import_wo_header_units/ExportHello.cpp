module;                 // global module fragment begins
#include <iostream>     // allowed here only

export module helloworld;  // must be first non-global-module declaration

export void hello() {
    std::cout << "Hello world!\n";
}
