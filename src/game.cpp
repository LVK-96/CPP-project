#include "game.hpp"


Game::Game(std::vector<Player> players, Map map, GameMode *mode): 
players_(players), map_(map), mode_(mode) {
	score_ = 0;
	fillMap(); //fill map with random numbers
	while(clearMatches()) {fillMap();}
	score_ = 0;
}

Game::~Game(){
	delete mode_;
}

 Map Game::getMap(){
	 //return the games map object for use outside of this class
	 return this->map_;
}

bool Game::clearMatches() {
	std::vector<std::vector<int> > matrix = map_.getMatrix(); //perform checks on this copy 
	bool ret = false;
	int matches = 0;
	for (int j = 0; j < (int) matrix.size(); j++) {
		for (int i = 0; i < (int) matrix[j].size(); i++) {
			if(matrix[j][i] != -1) { //check only if not wall
				if (j-2 >= 0) {	//check y			
					if (matrix[j][i] == matrix[j-1][i] && matrix[j][i] == matrix[j-2][i]) {
						map_.setTile(i, j, 0);  
						map_.setTile(i, j-1, 0);
						map_.setTile(i, j-2, 0);
						matches += 1;
						ret = true;
						}
					}	
					
					if (i-2 >= 0) { //check x 
						if (matrix[j][i] == matrix[j][i-1] && matrix[j][i] == matrix[j][i-2]) {
							map_.setTile(i, j, 0); 
							map_.setTile(i-1, j, 0);
							map_.setTile(i-2, j, 0);
							matches += 1;
							ret = true;
						}
					}
			}
		}
	}
	addScore(matches);
	return ret;
}

void Game::fillMap() {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	srand(time(NULL)); //intialize random seed
	
	for (unsigned int j = 0; j < matrix.size(); j++) {
		for (unsigned int i = 0; i < matrix[j].size(); i++) {
			if (matrix[j][i] == 0) {
				if ( (getScore() % 100 > 10) && (getScore() % 100 < 30) ) {
					map_.setTile(i, j, rand() % 5 + 1);
				}
				
				else {
					map_.setTile(i, j, rand() % 4 + 1);
				}
			}
		}
	}
}

bool Game::dropTiles() {
	bool ret = false;
	for (unsigned int i = 0; i < map_.getMatrix()[0].size(); i++) {
		std::vector<int> tmp_arr;
		for (unsigned int tmp = 0; tmp < map_.getMatrix().size(); tmp++) { //get column into array
			if(map_.getTile(i, tmp) >= 0){
				tmp_arr.push_back(map_.getTile(i, tmp));
			}
		}
		
		if (tmp_arr.size() > 0) {
			for (int j = tmp_arr.size()-2; j >= 0; j--) {
				if (tmp_arr[j+1] == 0 && tmp_arr[j] != 0) {
					int a = tmp_arr[j];
					tmp_arr[j+1] = a;
					tmp_arr[j] = 0;
					ret = true;
				}
			}	

			int k = 0;//index the sorted array without walls
			for (unsigned int tmp = 0; tmp < map_.getMatrix().size(); tmp++) { //set sorted array into map 
				if(map_.setTile(i, tmp, tmp_arr[k])) {
					k++;
				}
				else continue;
			}
		}
		
	}
	return ret;
}

bool Game::swapCoords(int x1, int y1, int x2, int y2) {
	int clr1 = map_.getTile(x1, y1);
	int clr2 = map_.getTile(x2, y2);
    map_.setTile(x1, y1, map_.getTile(x2, y2)); 
    map_.setTile(x2, y2, clr1);
		
	int i = 0;
	//special tile
	if (clr1 == 5 || clr2 == 5) {
		specialEffect5(clr1, clr2);
		i = 1;
	}
	
	else if (clearMatches()){i++;}

	if(i == 0) {
		clr1 = map_.getTile(x1, y1);
    	map_.setTile(x1, y1, map_.getTile(x2, y2));
		map_.setTile(x2, y2, clr1);
		return false;
	}
	
	return true;
}

bool Game::isAdjacent (int x1, int y1, int x2, int y2) const {
    if((x1-1 == x2 || x1+1 == x2) && y1 == y2) {return true;} 
	if((y1+1 == y2 || y1-1 == y2) && x1 == x2) {return true;}
	return false;
}

float Game::getTime() {
	sf::Time elapsed = clock_.getElapsedTime();
    float dt=elapsed.asSeconds();
	return dt;
}

void Game::addScore(int matches) {
	score_ += 10 * pow(matches, 3);
}

int Game::getScore() {
	return score_;
}

void Game::saveScore() {
	std::ofstream myfile;
  	myfile.open ("highscore_.txt", std::ofstream::app);
  	myfile << "Player1 " << std::to_string(getScore()) << "\n";
  	myfile.close();
}

void Game::specialEffect5(int color1, int color2) {
	std::vector<std::vector<int> > matrix = map_.getMatrix();
	for (unsigned int i = 0; i < map_.getMatrix()[0].size(); i++) {
		for (unsigned int j = 0; j < map_.getMatrix().size(); j++) {
			if(matrix[j][i] == color1 || matrix[j][i] == color2)
				map_.setTile(i, j, 0);
		}
	}
}

