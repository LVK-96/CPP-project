#pragma once
#include "gamemode.hpp"
#include <iostream>
/*Timeattack gamemode. Inherits GameMode*/

class TimeAttack : public GameMode{
    public:
        TimeAttack(std::string name);
        ~TimeAttack() = default;

        std::string getName() const;

        bool checkSpecialEndCondition(float dt);
        float getMaxTime(){return maxtime_;}
        void addTime();
    private:
        std::string name_;
        float maxtime_;
};