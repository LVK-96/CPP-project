#include <iostream>
#include "game.hpp"

Game::Game(std::vector<Player> players, Map map, GameMode mode): 
players_(players), map_(map), mode_(mode) {}

void Game::updateMap() {
    printMap(map_);
    checkMove();
}

void Game::checkMove() {
    bool is_valid = false;
    Map new_map = map_; //create new matrix for testing if move is valid
    
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
        new_map.setMatrix(coordx1, coordy1, map_.getColor(coordx2, coordy2)); //swap coords
        new_map.setMatrix(coordx2, coordy2, map_.getColor(coordx1, coordy1));

        std::pair<int, int > matching_1_x = checkX(new_map, coordx1, coordy1); //check 1 in x-direction
        std::pair<int, int> matching_1_y = checkY(new_map, coordx1, coordy1); //check 1 in y-direction

        std::pair<int, int> matching_2_x = checkX(new_map, coordx2, coordy2); //check 2 in x-direction
        std::pair<int, int> matching_2_y = checkY(new_map, coordx2, coordy2); //check 2 in y-direction 

        if (matching_1_x.first+matching_1_x.second+1 >= 3) {
            //remove row 1 in x direction
            removeX(coordx1, coordy1, matching_1_x, new_map);
            is_valid = true;
        }
        else if (matching_1_y.first+matching_1_y.second+1  >= 3) {
            //remove column 1 in y direction
            removeY(coordx1, coordy1, matching_1_y, new_map);
            is_valid = true; 
        }
        else if(matching_2_x.first+matching_2_x.second+1 >= 3) {
            //remove row 2 in x direction
            removeX(coordx2, coordy2, matching_2_x, new_map);
            is_valid = true; 
        }
        else if(matching_2_y.first+matching_2_y.second+1 >= 3) {
            //remove column 2 in y direction
            removeY(coordx2, coordy2, matching_2_y, new_map);
            is_valid = true;
        }
    }
    //set new map
    std::cout<<"Valid move"<<std::endl;
    std::cout<<"new_map"<<std::endl;
    printMap(new_map);
    std::cout<<std::endl;
    map_ = new_map;
}

void Game::tickGame() { //run game loop
    while(1) {
        updateMap();
    }
}

std::pair<int, int> Game::checkX(Map map, int x, int y) const {
    int color = map.getColor(x, y);

    //check to right
    int matching_right = 0; 
    for (std::vector<int>::iterator i = map.getMatrix()[y].begin() + x; i < map.getMatrix()[y].end(); i++) {
        if (*i == color) {matching_right++;}
    }
    //check to left
    int matching_left = 0;
    for (std::vector<int>::iterator i = map.getMatrix()[y].begin() + x; i > map.getMatrix()[y].begin(); i--) {
        if (*i == color) {matching_left++;}
    }

    return std::pair<int, int> (matching_right, matching_left);
}

std::pair<int, int> Game::checkY(Map map, int x, int y) const {
    int color = map.getColor(x,y);

    //check downwards
    int matching_down = 0;
    for (std::vector<std::vector<int> >::iterator i = map.getMatrix().begin() + y; i < map.getMatrix().end(); i++) {
        if((*i)[x] == color) {matching_down++;}
    }

    //check upwards
    int matching_up = 0;
    for (std::vector<std::vector<int> >::iterator i = map.getMatrix().begin() + y; i > map.getMatrix().end(); i--) {
        if((*i)[x] == color) {matching_up++;}
    }
    return std::pair<int, int> (matching_down, matching_up);
}

bool Game::isAdjacent (int x1, int y1, int x2, int y2) const {
    if(x1-1 == x2 || x1+1 == x2 || y1+1 == y2 || y1-1 == y2) {return true;}
    return false;
}

void Game::removeX(int x, int y, std::pair<int, int> matching, Map& map) const {
    //remove to right
    for (std::vector<int>::iterator i = map.getMatrix()[y].begin() + x; i < map.getMatrix()[y].begin()+x+matching.first; i++) {
        *i = 0;
    }

    //remove to left 
    for (std::vector<int>::iterator i = map.getMatrix()[y].begin() + x; i < map.getMatrix()[y].begin()+x-matching.second; i--) {
        *i = 0;
    } 
    //remove pivot point
    map.getMatrix()[y][x] = 0;

    std::cout<<"Map after removes"<<std::endl;
    printMap(map);
    std::cout<<std::endl; 
}

void Game::removeY(int x, int y, std::pair<int, int> matching, Map& map) const {
    //remove downwards
    for(std::vector<std::vector<int> >::iterator i = map.getMatrix().begin() + y; i < map.getMatrix().begin()+y+matching.first; i++) {
        (*i)[x] = 0;    
    }

    //remove upwards
    for(std::vector<std::vector<int> >::iterator i = map.getMatrix().begin() + y; i < map.getMatrix().begin()+y-matching.second; i--) {
        (*i)[x] = 0;
    }

    //remove pivot point
    map.getMatrix()[y][x] = 0;
}

void Game::printMap(Map map) const {
    for (auto i : map.getMatrix()) {
        for (auto j : i) {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
