#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.hpp"

Game::Game(std::vector<Player> players, Map map, GameMode mode): 
players_(players), map_(map), mode_(mode) {}

void Game::updateMap() {
    printMap(); //call GUI update here 
    checkMove(); //play turn
}

void Game::tickGame() { //run game loop
    while(1) {
        updateMap();
    }
}

void Game::checkMove() {
    bool is_valid = false;
    
    while (is_valid == false) { //loop until valid move
        std::cout<<"Gib coodrinates 1"<<std::endl; //read first coords
        int coordx1;
        int coordy1;
        std::cin>>coordx1;
        std::cin>>coordy1;

        bool check_adjacent = false;
        int coordx2;
        int coordy2;
        
        while (check_adjacent == false) { //loop untill we get adjacent pairs
            std::cout<<"Gib coodrinates 2"<<std::endl; //read second coords
            std::cin>>coordx2;
            std::cin>>coordy2;
            check_adjacent = isAdjacent(coordx1, coordy1, coordx2, coordy2); //check if coords are adjacent
        }

        std::cout<<"Valid pair"<<std::endl;
    
        //INSERT GAME LOGIC HERE//
        int tmpclr = map_.getColor(coordx1, coordy1);
        map_.setTile(coordx1, coordy1, map_.getColor(coordx2, coordy2)); //swap coords
        map_.setTile(coordx2, coordy2, tmpclr);

		clearMatches();
		dropTiles();
        fillMap();
    }
    
    std::cout<<"Valid move"<<std::endl;
    std::cout<<"New map:"<<std::endl;
}


void Game::clearMatches() {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	
	unsigned int = 0;
	for (unsigned int j = 0; j < matrix.size(); j++) {
		if ( (j-2) >= 0) {
			if ( (matrix[j-1][i] == matrix[j][i]) && (matrix[j-2][i] == matrix[j][i]) ) {
				map._setTile(i, j, 0);
				map._setTile(i, j-1, 0);
				map._setTile(i, j-2, 0);
			}
		}
		
		for (i = 0; i < matrix[j].size(); i++) {
			if ( (i-2) >= 0) {
				if ( (matrix[j][i-1] == matrix[j][i]) && (matrix[j][i-2] == matrix[j][i]) ) {
					map._setTile(i, j, 0);
					map._setTile(i-1, j, 0);
					map._setTile(i-2, j, 0);
				}
			}
		}
	}
}

void Game::fillMap() {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	
	//intialize random seed
	srand(time(NULL));

	//loops through the map and fills empty spaces with random tiles
	unsigned int = 0;
	for (unsigned int j = 0; j < matrix.size(); j++) {
		for (i = 0; i < matrix[j].size(); i++) {
			if (matrix[j][i] == 0) {
				map_.setTile(i, j, rand() % 4 + 1);
			}
		}
	}
}

void Game::dropTiles() {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	
	unsigned int = 0;
	for (unsigned int j = matrix.size(); j > 0; j--) {
		for (i = matrix[j].size(); i > 0; i--) {
			if ( (j+1) < matrix.size() ) {
				
			}
		}
	}
}

bool Game::isAdjacent (int x1, int y1, int x2, int y2) const {
    if(x1-1 == x2 || x1+1 == x2 || y1+1 == y2 || y1-1 == y2) {return true;}
    return false;
}

void Game::printMap() const {
    for (auto i : map_.getMatrix()) {
        for (auto j : i) {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
