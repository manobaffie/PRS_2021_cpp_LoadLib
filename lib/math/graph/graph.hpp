#include <vector>
#include <iostream>

class graph
{
    private:
        std::vector<std::vector<float>> value;

    public:
        graph(int dimension);
        ~graph();

        void linkPoint();
        void setPoint();

        float distance();
};

