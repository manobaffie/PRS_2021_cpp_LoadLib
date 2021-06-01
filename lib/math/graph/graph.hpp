#include <vector>
#include <iostream>

struct point
{
    std::string name;
    std::vector<point *> p;
};

class graph3D
{
    private:
        std::vector<std::vector<std::vector<point>>> value;

    public:
        graph3D(int xSize, int ySize, int zSize);
        ~graph3D();

        void linkPoint();
        void setPoint();

        float distance();
};

