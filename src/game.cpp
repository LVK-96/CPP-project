#include <iostream>
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
        map_.setMatrix(coordx1, coordy1, map_.getColor(coordx2, coordy2)); //swap coords
        map_.setMatrix(coordx2, coordy2, map_.getColor(coordx1, coordy1));

        std::pair<int, int > matching_1_x = checkX(coordx1, coordy1); //check 1 in x-direction
        std::pair<int, int> matching_1_y = checkY(coordx1, coordy1); //check 1 in y-direction

        std::pair<int, int> matching_2_x = checkX(coordx2, coordy2); //check 2 in x-direction
        std::pair<int, int> matching_2_y = checkY(coordx2, coordy2); //check 2 in y-direction 
        
        if (matching_1_x.first+matching_1_x.second+1 >= 3) {
            //remove row 1 in x direction
            removeX(coordx1, coordy1, matching_1_x);
            is_valid = true;
        }
        if (matching_1_y.first+matching_1_y.second+1  >= 3) {
            //remove column 1 in y direction
            removeY(coordx1, coordy1, matching_1_y);
            is_valid = true; 
        }
        if(matching_2_x.first+matching_2_x.second+1 >= 3) {
            //remove row 2 in x direction
            removeX(coordx2, coordy2, matching_2_x);
            is_valid = true; 
        }
        if(matching_2_y.first+matching_2_y.second+1 >= 3) {
            //remove column 2 in y direction
            removeY(coordx2, coordy2, matching_2_y);
            is_valid = true;
        }
    }
    //set new map
    std::cout<<"Valid move"<<std::endl;
    std::cout<<"New map:"<<std::endl;
}

std::pair<int, int> Game::checkX(int x, int y) const {
    int color = map_.getColor(x, y);

    //check to right
    int matching_right = 0; 
    for (std::vector<int>::iterator i = map_.getMatrix()[y].begin() + x; i < map_.getMatrix()[y].end(); i++) {
        if (*i == color) {matching_right++;}
    }
    //check to left
    int matching_left = 0;
    for (std::vector<int>::iterator i = map_.getMatrix()[y].begin() + x; i > map_.getMatrix()[y].begin(); i--) {
        if (*i == color) {matching_left++;}
    }

    return std::pair<int, int> (matching_right, matching_left);
}

std::pair<int, int> Game::checkY(int x, int y) const {
    int color = map_.getColor(x,y);

    //check downwards
    int matching_down = 0;
    for (std::vector<std::vector<int> >::iterator i = map_.getMatrix().begin() + y; i < map_.getMatrix().end(); i++) {
        if((*i)[x] == color) {matching_down++;}
    }

    //check upwards
    int matching_up = 0;
    for (std::vector<std::vector<int> >::iterator i = map_.getMatrix().begin() + y; i > map_.getMatrix().end(); i--) {
        if((*i)[x] == color) {matching_up++;}
    }
    return std::pair<int, int> (matching_down, matching_up);
}

bool Game::isAdjacent (int x1, int y1, int x2, int y2) const {
    if(x1-1 == x2 || x1+1 == x2 || y1+1 == y2 || y1-1 == y2) {return true;}
    return false;
}

void Game::removeX(int x, int y, std::pair<int, int> matching) {
    //remove to right
    for (std::vector<int>::iterator i = map_.getMatrix()[y].begin() + x; i < map_.getMatrix()[y].begin()+x+matching.first; i++) {
        *i = 0;
        std::cout<<"After removeX"<<std::endl;
        printMap();
        std::cout<<"//////////////////////"<<std::endl;
    }

    //remove to left 
    for (std::vector<int>::iterator i = map_.getMatrix()[y].begin() + x; i > map_.getMatrix()[y].begin()+x-matching.second; i--) {
        *i = 0;
    } 
    //remove pivot point
    map_.getMatrix()[y][x] = 0;
}

void Game::removeY(int x, int y, std::pair<int, int> matching) {
    //remove downwards
    for(std::vector<std::vector<int> >::iterator i = map_.getMatrix().begin() + y; i < map_.getMatrix().begin()+y+matching.first; i++) {
        (*i)[x] = 0;    
    }

    //remove upwards
    for(std::vector<std::vector<int> >::iterator i = map_.getMatrix().begin() + y; i > map_.getMatrix().begin()+y-matching.second; i--) {
        (*i)[x] = 0;
    }

    //remove pivot point
    map_.getMatrix()[y][x] = 0;
    
    std::cout<<"After remove Y"<<std::endl;
    printMap();
    std::cout<<"//////////////////////"<<std::endl;
}

void Game::printMap() const {
    for (auto i : map_.getMatrix()) {
        for (auto j : i) {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
