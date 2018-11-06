#pragma once 
#include <utility>

class Player {
public:
    Player();

    int getId() const;
    std::pair<int, int> getPos() const;
    void setPos(std::pair<int, int> pos);

protected:
    int id_;
    std::pair<int, int> pos_;

};