#include "gamemode.hpp"

GameMode::GameMode(std::string name):name_(name) {}

std::string GameMode::getName() const {
	std::cout << "gamemode getname called, name: " << name_ << std::endl; 
	return name_;
}

bool GameMode::checkSpecialEndCondition(float dt){
		std::cout << "std special condition check is called" << std::endl;
        return false;
}

bool GameMode::checkBaseEndCondition(Map map){

	std::cout << "checking base end condition" << std::endl;
	if(checkSpecialEndCondition(0)){
		std::cout << "special End condition returned true" << std::endl;
		return true;
	}
	std::cout << "checking special end condition returned false" << std::endl;
    //indexing is [y][x], but getTile gives x, y --> matrix is looped through column by column
    int i = 1;
    //check if possible moves exist

    for (unsigned int x = 0; x < map.getMatrix().size(); x++ ) {
		for (unsigned int y = 0; y < map.getMatrix()[0].size(); y++) {
            std::cout << std::endl << i <<std::endl;
			if (x < map.getMatrix().size() - 2) {
				//check x
                std::cout << "checking x" << std::endl;
				if (map.getTile(x, y) == map.getTile(x+1, y) && map.getTile(x+2, y) != -1 && map.getTile(x, y) != -1) {
					//11+
                    std::cout << "found 11+" << std::endl;

					if (y > 0) {
						//check[x + 2][y-1]
						if (map.getTile(x, y) == map.getTile(x+2, y-1)) {
                            std::cout << "possible move at: " << x+2 << ", " << y-1 <<std::endl;
							return true;
						}
					}
					if (x + 3 < map.getMatrix().size()) {
						//check[x + 3][y]	
						if (map.getTile(x, y) == map.getTile(x + 3, y)) {
                            std::cout << "possible move at: " << x+3<< ", " << y <<std::endl;
							return true;
						}
					}

					//check[x+2][y+1]
                    if(y + 1 < map.getMatrix().size()){
                        if (map.getTile(x, y) == map.getTile(x+2, y+1)) {
                            std::cout << "possible move at: " << x+2<< ", " << y+1 <<std::endl;
						    return true;
					    }
                    }
				}


				else if (map.getTile(x+1, y) == map.getTile(x+2, y) && map.getTile(x,y) != -1 && map.getTile(x + 1, y) != -1) {
					//+11
                    std::cout << "found +11" << std::endl;
					if (y > 0) {
						//check[x][y-1]
						if (map.getTile(x+1, y) == map.getTile(x, y-1)) {
                            std::cout << "possible move at: " << x<< ", " << y-1 <<std::endl;
							return true;
						}
					}
					if (x > 0) {
						//check[x-1][y]	
						if (map.getTile(x+1, y) == map.getTile(x-1, y)) {
                            std::cout << "possible move at: " << x-1<< ", " << y <<std::endl;
							return true;
						}
					}

                    if(y+1<map.getMatrix().size()){
                        //check [x][y+1]
					    if (map.getTile(x+1, y) == map.getTile(x, y+1)) {
                            std::cout << "possible move at: " << x<< ", " << y+1 <<std::endl;
						    return true;
					    }
                    }
					

				}
				else if (map.getTile(x, y) == map.getTile(x+2, y) && map.getTile(x+1,y) != -1 && map.getTile(x, y) != -1) {
					//1+1
                    std::cout << "found 1+1" << std::endl;
					//check that within index
					if (y > 0) {
						//check [x+1][y-1]
						if (map.getTile(x, y) == map.getTile(x+1, y-1)) {
                            std::cout << "possible move at: " << x+1<< ", " << y-1 <<std::endl;
							return true;
						}
					}
                    if(y + 1 < map.getMatrix()[0].size()){
                        //check [x+1][y+1]
					    if (map.getTile(x, y) == map.getTile(x+1, y+1)) {
                            std::cout << "possible move at: " << x+1<< ", " << y+1 <<std::endl;
						    return true;
					    }
                    }
				}
			}
			





			if (y < map.getMatrix()[0].size() - 2) {
				//check y
                std::cout << "checking y" << std::endl;
                if (map.getTile(x, y) == map.getTile(x, y + 1)  && map.getTile(x,y + 2) != -1 && map.getTile(x, y) != -1) {
					//1
                    //1
                    //+
                    std::cout << "found 1\n1\n+" << std::endl;

					if (x > 0) {
						//check[x - 1][y + 2]
						if (map.getTile(x, y) == map.getTile(x-1, y+2)) {
                            std::cout << "possible move at: " << x-1<< ", " << y+2 <<std::endl;
							return true;
						}
					}
					if (y + 3 < map.getMatrix()[0].size()) {
						//check[x][y + 3]	
						if (map.getTile(x, y) == map.getTile(x, y + 3)) {
                            std::cout << "possible move at: " << x<< ", " << y+3 <<std::endl;
							return true;
						}
					}

                    if(x + 1 < map.getMatrix().size()){
                        //check[x+1][y+2]
					    if (map.getTile(x, y) == map.getTile(x+1, y+2)) {
                            std::cout << "possible move at: " << x+1<< ", " << y+2 <<std::endl;
						    return true;
					    }
                    }
				}


				else if (map.getTile(x, y+1) == map.getTile(x, y+2)  && map.getTile(x,y) != -1 && map.getTile(x, y + 1) != -1) {
					//+
                    //1
                    //1
                    std::cout << "found +\n1\n1" << std::endl;
					if (x > 0) {
						//check[x - 1][y]
						if (map.getTile(x, y+1) == map.getTile(x - 1, y)) {
                            std::cout << "possible move at: " << x-1<< ", " << y <<std::endl;
							return true;
						}
					}
					if (y > 0) {
						//check[x][y - 1]	
						if (map.getTile(x, y+1) == map.getTile(x, y - 1)) {
                            std::cout << "possible move at: " << x<< ", " << y-1 <<std::endl;
							return true;
						}
                    }

					//check [x + 1][y]
                    if(x+1<map.getMatrix().size()){
                        if (map.getTile(x, y + 1) == map.getTile(x + 1, y)) {
                            std::cout << "possible move at: " << x+1<< ", " << y <<std::endl;
						return true;
					    }
                    }

				}
				else if (map.getTile(x, y) == map.getTile(x, y + 2)  && map.getTile(x,y + 1) != -1 && map.getTile(x, y) != -1) {
					//1
                    //+
                    //1
                    std::cout << "found 1\n+\n1" << std::endl;
					//check that within index
					if (x > 0) {
						//check [x-1][y+1]
						if (map.getTile(x, y) == map.getTile(x-1, y+1)) {
                            std::cout << "possible move at: " << x-1<< ", " << y+1 <<std::endl;
							return true;
						}
					}

                    if(x + 1 < map.getMatrix().size()){
                        //check [x+1][y+1]
                        if (map.getTile(x, y) == map.getTile(x+1, y+1)) {
                            std::cout << "possible move at: " << x+1<< ", " << y+1 <<std::endl;
						return true;
					    }
                    }
				}

			}
            i++;

		}
	    
    }


    for (unsigned int x = 0; x < map.getMatrix().size(); x++ ) {
		for (unsigned int y = 0; y < map.getMatrix()[0].size(); y++) {
            //check for special tile -- doesnt determine whether it can be swapped at all
            if(map.getTile(x, y) == 5){
                return true;
            }
        }
    }


    return false;
}