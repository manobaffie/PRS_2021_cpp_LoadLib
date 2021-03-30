#include <iostream>

#include "../ILib.hpp"

class hello : public ILib
{
    private:
        std::string from;

    public:
        hello();
        ~hello() override;

        void printHello() override;
};
