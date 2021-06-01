#include "graph.hpp"

graph3D::graph3D(int xSize, int ySize, int zSize)
{
    std::vector<point> zTmp;
    std::vector<std::vector<point>> yTmp;
    point p;

    for (int i = 0; i < zSize; i++) {
        zTmp.push_back(p);
    }
    for (int i = 0; i < ySize; i++) {
        yTmp.push_back(zTmp);        
    }
    for (int i = 0; i < xSize; i++) {
        this->value.push_back(yTmp);
    }
}

graph3D::~graph3D()
{
}

void graph3D::linkPoint()
{
    
}