#include <iostream>

// #include "../lib/MapFunc/MapFunc.hpp"
#include "../lib/JsonPars/JsonPars.hpp"
// #include "../lib/LoadLib/LoadLib.hpp"
// #include "../lib/Log/Log.hpp"

// #include "../lib/LoadLib/ILib.hpp"


int main()
{
    std::cout << "=== start ===" << std::endl;

    JsonPars j("./test/conf hard.json");
    // JsonPars j("./test/conf.json");


    std::cout << j.getJson()["game"].m["p_lib"].s << std::endl;

    std::cout << j.getJson()["sprite"].m["perso"].m["part"].tm.size() << std::endl;

    // std::cout << j.getJson()["sprite"].m["name"].s << std::endl;
    // std::cout << j.getJson()["map"].m["name"].s << std::endl;

    return (0);
}