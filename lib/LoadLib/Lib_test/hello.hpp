#include <iostream>

#include <SFML/Graphics.hpp>

#include "../ILib.hpp"

class hello : public ILib
{
    private:
        std::string from;
        sf::RenderWindow window;

    public:
        hello(std::string f);
        ~hello() override;

        void printHello() override;
};
