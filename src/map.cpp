#include "map.hpp"

Map::Map(std::vector<std::vector<int> > map): matrix_(map) {}
std::vector<std::vector<int> > Map::getMatrix() const {return matrix_;}
void Map::setMatrix (int x, int y) {matrix_[y][x] = 1;} 
