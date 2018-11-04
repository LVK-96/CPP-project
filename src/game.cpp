#include <iostream>
#include "game.hpp"

Game::Game(std::vector<Player> players, Map map, GameMode mode): 
players_(players), map_(map), mode_(mode) {}

void Game::updateMap() {
    for (auto i : map_.getMatrix()) {
        for (auto j : i) {
            std::cout<<j;
        }
        std::cout<<std::endl;
    }
    checkMove();
}

void Game::checkMove() {
    std::cout<<"Gib coodrinates"<<std::endl;
    int coordx;
    int coordy;
    std::cin>>coordx;
    std::cin>>coordy;

    //INSERT GAME LOGIC HERE//
    
    map_.setMatrix(coordx, coordy);
}

void Game::tickGame() {
    while(1) {
        updateMap();
    }
}
