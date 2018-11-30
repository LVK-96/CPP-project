#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.hpp"
#include "guiwindow.hpp"
#include "algorithm"

Game::Game() = default;

Game::Game(std::vector<Player> players, Map map, GameMode mode, GUIWindow window): 
players_(players), map_(map), mode_(mode), window_(window) {
	fillMap(); //fill map with random numbers
	while(clearMatches()) { 
		fillMap(); //clear and fill until no more matches
	}
}

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
        /*std::cout<<"Gib coodrinates 1"<<std::endl; //read first coords
        int coordx1;
        int coordy1;
        std::cin>>coordx1;
        std::cin>>coordy1;

		int coordx2;
        int coordy2;        
        
        while (check_adjacent == false) { //loop untill we get adjacent pairs
            std::cout<<"Gib coodrinates 2"<<std::endl; //read second coords
            std::cin>>coordx2;
            std::cin>>coordy2;
            check_adjacent = isAdjacent(coordx1, coordy1, coordx2, coordy2); //check if coords are adjacent
        }*/
		std::vector<unsigned int> mouseClicks;
    	bool check_adjacent = false;
		while(check_adjacent == false) {		
			mouseClicks = window_.getInput(map_.getMatrix());
			check_adjacent = isAdjacent(mouseClicks[0], mouseClicks[1], mouseClicks[2], mouseClicks[3]); //check if coords are adjacent
		}
        //INSERT GAME LOGIC HERE//
        swapCoords(mouseClicks[0], mouseClicks[1], mouseClicks[2], mouseClicks[3]);
		while(clearMatches()) {
			std::cout<<"cleared"<<std::endl;
			printMap();
			
			dropTiles();
			std::cout<<"dropped"<<std::endl;
			printMap();

			fillMap();
			std::cout<<"filled"<<std::endl;
			printMap();
			
			is_valid = true;
		}
    }
    
    std::cout<<"Valid move"<<std::endl;
    std::cout<<"New map:"<<std::endl;
}


bool Game::clearMatches() {
	std::vector<std::vector<int> > matrix = map_.getMatrix(); //perform checks on this copy 
	bool ret = false;

	for (int j = 0; j < (int) matrix.size(); j++) {
		for (int i = 0; i < (int) matrix[j].size(); i++) {
			if (j-2 >= 0) {	//check y			
				if (matrix[j][i] == matrix[j-1][i] && matrix[j][i] == matrix[j-2][i]) {
					map_.setTile(i, j, 0);  
					map_.setTile(i, j-1, 0);
					map_.setTile(i, j-2, 0);
					ret = true;
				}
			}	
			if (i-2 >= 0) { //check x 
				if (matrix[j][i] == matrix[j][i-1] && matrix[j][i] == matrix[j][i-2]) {
					map_.setTile(i, j, 0); 
					map_.setTile(i-1, j, 0);
					map_.setTile(i-2, j, 0);
					ret = true;
				}
			}
		}
	}
	return ret;	
}

void Game::fillMap() {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	
	//intialize random seed
	srand(time(NULL));

	//loops through the map and fills empty spaces with random tiles
	for (unsigned int j = 0; j < matrix.size(); j++) {
		for (unsigned int i = 0; i < matrix[j].size(); i++) {
			if (matrix[j][i] == 0) {
				map_.setTile(i, j, rand() % 4 + 1);
			}
		}
	}
}

void Game::dropTiles() {
	for (unsigned int i = 0; i < map_.getMatrix()[0].size(); i++) {
		std::vector<int> tmp_arr;
		for (unsigned int tmp = 0; tmp < map_.getMatrix().size(); tmp++) { //get column into array 
			tmp_arr.push_back(map_.getTile(i, tmp));
		}

		std::sort(tmp_arr.begin(), tmp_arr.end(), 
		[] (int a, int b) {
			if (a != 0 && b != 0) {a = b;} //two ints != 0 are equal so 0s end up on top
			return (a < b);
		});

		for (unsigned int tmp = 0; tmp < map_.getMatrix().size(); tmp++) { //set sorted array into map 
			map_.setTile(i, tmp, tmp_arr[tmp]);
		}
	} 
}

void Game::swapCoords(int x1, int y1, int x2, int y2) {
	int tmpclr = map_.getTile(x1, y1);
	std::cout << x1 << y1 << x2 << y2 << std::endl;
    map_.setTile(x1, y1, map_.getTile(x2, y2)); 
    map_.setTile(x2, y2, tmpclr);
}

bool Game::isAdjacent (int x1, int y1, int x2, int y2) const {
    if((x1-1 == x2 || x1+1 == x2) && y1 == y2) {return true;} 
	if((y1+1 == y2 || y1-1 == y2) && x1 == x2) {return true;}
	return false;
}

void Game::printMap() const {
     std::cout<<"/////////////////"<<std::endl;
	for (auto i : map_.getMatrix()) {
        for (auto j : i) {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"/////////////////"<<std::endl;
	window_.draw(map_.getMatrix());

}
