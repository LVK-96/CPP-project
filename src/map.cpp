#include "map.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Map::Map(std::vector<std::vector<int> > map): matrix_(map) {}
std::vector<std::vector<int> > Map::getMatrix() const {return matrix_;} 
void Map::setTile (int x, int y, int color) {matrix_[y][x] = color;}
int Map::getTile(int x, int y) const {return matrix_[y][x];}


