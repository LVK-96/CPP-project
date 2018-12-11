#pragma once
#include <string>
#include <vector>

#include "map.hpp"

class GameMode {
public:
    GameMode();

    std::string getName() const;
    bool checkBaseEndCondition(Map map);

protected:
    std::string name_;
};