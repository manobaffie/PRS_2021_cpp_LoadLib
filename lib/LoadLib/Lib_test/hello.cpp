#include "hello.hpp"

hello::hello()
{
    this->from = "hello from : ";
}

hello::~hello()
{
    std::cout << "good bye" << std::endl;
}

void hello::printHello()
{
    std::cout << this->from << std::endl;
}

extern "C" {
    ILib* create() {
        return new hello();
    }

    void destroy(hello* obj) {
        delete obj;
    }
}