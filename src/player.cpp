#include "player.hpp"

Player::Player(): id_(0), pos_(std::pair<int, int>(0,0)) {} //set id to 0 and pos to 0,0
int Player::getId() const {return id_;}
std::pair<int, int> Player::getPos() const {return pos_;}
void Player::setPos(std::pair<int, int> pos) {pos_ = pos;}