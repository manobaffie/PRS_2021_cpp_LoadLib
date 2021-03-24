#include <iostream>
#include <variant>
#include <any>

#include "../lib/MapFunc/MapFunc.hpp"
#include "../lib/JsonPars/JsonPars.hpp"

int main()
{
    std::cout << "=== start ===" << std::endl;

    JsonPars jp("./test.json");

    std::cout << jp.getJson().nbr.find("number_of_thread")->second << std::endl;
    std::cout << jp.getJson().obj.find("test0")->second.nbr.find("nb")->second << std::endl;
    std::cout << jp.getJson().obj.find("test0")->second.obj.find("testttt")->second.str.find("2")->second << std::endl;
    std::cout << jp.getJson().

    return (0);
}