#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "map.hpp"

class GameMode {
public:
    GameMode() = default;
    GameMode(std::string name);


    std::string getName() const;
    bool checkBaseEndCondition(Map map);
    std::string getName(){return name_;}

    //virtual
    virtual bool checkSpecialEndCondition(float dt){}


protected:
    std::string name_;
};