#include "timeattack.hpp"

TimeAttack::TimeAttack(std::string name) : name_(name), maxtime_(100.0){
    std::cout << "time attacks constructor" << std::endl;
}

std::string TimeAttack::getName() const{
    return name_;
}

bool TimeAttack::checkSpecialEndCondition(float dt){
    std::cout << "checking special end condition for time attack" << std::endl;
    if(dt < maxtime_){
        return true;
    }
    else{
        return false;
    }
}