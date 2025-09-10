// EXAMPLE SUMMARY
// This is a workaround to the standard way of using modules TS that bypasses header-units imports
// and load standard libraries in the old way.
// Doing this, we avoid having to compile each standard library individually for each build.
// This workaround is not expected to be necessary in C++23.

// COMPILING INSTRUCTIONS 
// Requires g++ >= 13
//
// Run with:
// g++ -std=c++20 -fmodules-ts -c -o ExportHello.o ExportHello.cpp
// g++ -std=c++20 -fmodules-ts -c ImportHello.cpp
// g++ ExportHello.o ImportHello.o -o hello
// ./hello
// 
// The flag -fmodules-ts is necessary to use import / export.

import helloworld;
 
int main()  {
    hello();
}