#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "map.hpp"

class GameMode {
public:
    GameMode();

    std::string getName() const;
    bool checkBaseEndCondition(Map map);
    std::string getName(){return name_;}

protected:
    std::string name_;
};