#include <vector>
#include "tilematching.hpp"

TileMatching::TileMatching() {
Player p1;
std::vector<Player> players;
players.push_back(p1);
Map map(std::vector<std::vector<int> >(8, std::vector<int>(8,1))); //8x8 zero matrix
GameMode mode;
setGame(Game(players, map, mode));
setStatus("game");
}

Game TileMatching::getGame() const {return game_;}
std::string TileMatching::getStatus() const {return status_;}
void TileMatching::setStatus(std::string new_status) {status_ = new_status;}
void TileMatching::setGame(Game new_game) {game_ = new_game;}
void TileMatching::runGame() {game_.tickGame();}