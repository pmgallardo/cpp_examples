// EXAMPLE SUMMARY
//
// This is the standard way in C++20 to use modules TS using import/export.

// COMPILATION INSTRUCTIONS
//
// Requires g++ >= 13
//
// Run with:
// g++ -std=c++20 -fmodules-ts -xc++-system-header -c iostream
// g++ -std=c++20 -fmodules-ts -c -o ExportHello.o ExportHello.cpp
// g++ -std=c++20 -fmodules-ts -c -o ImportHello.o ImportHello.cpp
// g++ ExportHelloC.o ImportHello.o -o hello
//
// The flag -fmodules-ts is necessary to use import / export.
//
// Under the C++20 Modules TS (as implemented in GCC), standard headers are not automatically available as modules.
// That's why we need to explicitly compile them into "BMI" (binary module interface) files first.

// EXECUTION INSTRUCTIONS
// ./hello


import helloworld;
 
int main()  {
    hello();
}