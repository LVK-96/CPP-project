#include "map.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
bool isValid(int x, int y, int tile, std::vector<std::vector<int>> m) {
		bool xcheck = false;
		bool ycheck = false;
		//m[y][x]
		//check left
		if(x == 0){
			xcheck = true;
		}
		
		if(x == 1){
			if(m[y][x-1] != tile){
				xcheck = true;			
			}
			else{
				return false;//if xcheck fails the whole func returns zero
			}
		}
		
		if(x >= 2){
			if(m[y][x-1] != tile && m[y][x-2] != tile){
				xcheck = true;
			}
			else{
				return false;	
			}
		}
		//check up

		if(y == 0){
			ycheck = true;
		}
		
		if(y == 1){
			if(m[y - 1][x] != tile){
				ycheck = true;			
			}
			else{
				return false;
			}
		}
		
		if(y >= 2){
			if(m[y-1][x] != tile && m[y-2][x] != tile){
				ycheck = true;
			}
			else{
				return false;	
			}
		}

		if(ycheck && xcheck){
			return true;		
		}
		else{
			return false;	
		}
	}
Map::Map() {
	


	std::vector<std::vector<int>> m;
	for (unsigned int i = 0; i < 8; i++) {
		std::vector<int> column(8);
		m.push_back(column);
		srand(time(NULL));
		for (unsigned int j = 0; j < 8; j++) {
			int random = rand() % 4 + 1;
			while (!isValid(i, j, random, m)) {
				random = rand() % 4 + 1;
			}
			m[i][j] = random;
		}
	}
}
std::vector<std::vector<int> > Map::getMatrix() const {return matrix_;}
void Map::setTile (int x, int y, int color) {matrix_[y][x] = color;}
int Map::getTile(int x, int y) const {return matrix_[y][x];}

