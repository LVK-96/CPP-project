#include "gamemode.hpp"

GameMode::GameMode() {name_ = "basic";}
std::string GameMode::getName() const {return name_;}



bool checkBaseEndCondition(Map map){

    //check if possible moves exist
    for (unsigned int x = 0; x < map.getMatrix().size(); x++ ) {
		for (unsigned int y = 0; y < map.getMatrix()[0].size(); y++) {
			if (x < map.getMatrix().size() - 2) {
				//check x
				if (map.getTile(x, y) == map.getTile(x+1, y)) {
					//11+


					if (y > 0) {
						//check[x + 2][y-1]
						if (map.getTile(x, y) == map.getTile(x+2, y-1)) {
							return true;
						}
					}
					if (x + 3 < map.getMatrix().size()) {
						//check[x + 3][y]	
						if (map.getTile(x, y) == map.getTile(x + 3, y)) {
							return true;
						}
					}

					//check[x+2][y+1]
                    if(y + 1 < map.getMatrix().size()){
                        if (map.getTile(x, y) == map.getTile(x+2, y+1)) {
						    return true;
					    }
                    }
				}


				else if (map.getTile(x+1, y) == map.getTile(x+2, y)) {
					//+11
					if (y > 0) {
						//check[x][y-1]
						if (map.getTile(x+1, y) == map.getTile(x, y-1)) {
							return true;
						}
					}
					if (x > 0) {
						//check[x-1][y]	
						if (map.getTile(x+1, y) == map.getTile(x-1, y)) {
							return true;
						}
					}

                    if(y+1<map.getMatrix().size()){
                        //check [x][y+1]
					    if (map.getTile(x+1, y) == map.getTile(x, y+1)) {
						    return true;
					    }
                    }
					

				}
				else if (map.getTile(x, y) == map.getTile(x+2, y)) {
					//1+1
					//check that within index
					if (y > 0) {
						//check [x+1][y-1]
						if (map.getTile(x, y) == map.getTile(x+1, y-1)) {
							return true;
						}
					}
                    if(y + 1 < map.getMatrix()[0].size()){
                        //check [x+1][y+1]
					    if (map.getTile(x, y) == map.getTile(x+1, y+1)) {
						    return true;
					    }
                    }
				}
			}
			





			if (y < map.getMatrix()[0].size() - 2) {
				//check y

                if (map.getTile(x, y) == map.getTile(x, y + 1)) {
					//1
                    //1
                    //+

					if (x > 0) {
						//check[x - 1][y + 2]
						if (map.getTile(x, y) == map.getTile(x-1, y+2)) {
							return true;
						}
					}
					if (y + 3 < map.getMatrix()[0].size()) {
						//check[x][y + 3]	
						if (map.getTile(x, y) == map.getTile(x, y + 3)) {
							return true;
						}
					}

                    if(x + 1 < map.getMatrix().size()){
                        //check[x+1][y+2]
					    if (map.getTile(x, y) == map.getTile(x+1, y+2)) {
						    return true;
					    }
                    }
				}


				else if (map.getTile(x, y+1) == map.getTile(x, y+2)) {
					//+
                    //1
                    //1
					if (x > 0) {
						//check[x - 1][y]
						if (map.getTile(x, y+1) == map.getTile(x - 1, y)) {
							return true;
						}
					}
					if (y > 0) {
						//check[x][y - 1]	
						if (map.getTile(x, y+1) == map.getTile(x, y - 1)) {
							return true;
						}
                    }

					//check [x + 1][y]
                    if(x+1<map.getMatrix().size()){
                        if (map.getTile(x, y + 1) == map.getTile(x + 1, y)) {
						return true;
					    }
                    }

				}
				else if (map.getTile(x, y) == map.getTile(x, y + 2)) {
					//1
                    //+
                    //1
					//check that within index
					if (x > 0) {
						//check [x-1][y+1]
						if (map.getTile(x, y) == map.getTile(x-1, y+1)) {
							return true;
						}
					}

                    if(x + 1 < map.getMatrix().size()){
                        //check [x+1][y+1]
                        if (map.getTile(x, y) == map.getTile(x+1, y+1)) {
						return true;
					    }
                    }
				}

			}

		}
	    
    }
    return false;
}