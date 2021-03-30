#include <iostream>

// #include "../lib/MapFunc/MapFunc.hpp"
// #include "../lib/JsonPars/JsonPars.hpp"
#include "../lib/LoadLib/LoadLib.hpp"

int main()
{
    std::cout << "=== start ===" << std::endl;

    LoadLib<ILib> Il("./lib/LoadLib/Lib_test/hello.so");

    ILib *hello = Il.init();

    hello->printHello();

    return (0);
}