#include "timeattack.hpp"

TimeAttack::TimeAttack(std::string name) : name_(name), maxtime_(100.0){}

std::string TimeAttack::getName() const{
    return name_;
}

bool TimeAttack::checkSpecialEndCondition(float dt){
    if(dt < maxtime_){
        return true;
    }
    else{
        return false;
    }
}