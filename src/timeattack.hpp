#pragma once

#include "gamemode.hpp"
#include <iostream>


class TimeAttack : public GameMode{
    public:
        TimeAttack(std::string name);
        ~TimeAttack() = default;

        std::string getName() const;

        bool checkSpecialEndCondition(float dt);

    private:
        std::string name_;
        float maxtime_;

};