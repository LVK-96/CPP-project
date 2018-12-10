#include "map.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Map::Map(std::vector<std::vector<int> > map): matrix_(map) {}
std::vector<std::vector<int> > Map::getMatrix() const {return matrix_;} 
bool Map::setTile (int x, int y, int color) 
{
    if(matrix_[y][x] > -1){
        //if not a wall
        matrix_[y][x] = color;
        return true;
    }
    else return false;//if wall
}
int Map::getTile(int x, int y) const {return matrix_[y][x];}


