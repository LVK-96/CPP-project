#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "map.hpp"

class GameMode {
public:
    GameMode() = default;
    GameMode(std::string name);
	
	GameMode& operator= (const GameMode& g) = default;
	GameMode(const GameMode& g) = default;

    virtual std::string getName() const;
    bool checkBaseEndCondition(Map map);

    //virtual
    virtual bool checkSpecialEndCondition(float dt);


protected:
    std::string name_;
};