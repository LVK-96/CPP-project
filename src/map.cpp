#include "map.hpp"


Map::Map(std::vector<std::vector<int> > map): matrix_(map) {}

std::vector<std::vector<int> > Map::getMatrix() const {return matrix_;} 

bool Map::setTile (int x, int y, int color) {
    if(matrix_[y][x] > -1){
        //if not a wall
        matrix_[y][x] = color;
        return true;
    }
    else return false;//if wall
}

int Map::getTile(int x, int y) const {return matrix_[y][x];}

void Map::setMatrix(std::vector<std::vector<int> > matrix) {
	matrix_ = matrix; 
}


