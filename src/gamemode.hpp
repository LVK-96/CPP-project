#pragma once
#include <string>

class GameMode {
public:
    GameMode();

    std::string getName() const;

protected:
    std::string name_;
};