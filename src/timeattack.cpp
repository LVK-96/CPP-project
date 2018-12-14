#include "timeattack.hpp"

TimeAttack::TimeAttack(std::string name) : name_(name), maxtime_(5.0){
    std::cout << "time attacks constructor" << std::endl;
}

std::string TimeAttack::getName() const{
    return name_;
}

bool TimeAttack::checkSpecialEndCondition(float timeElapsed){
    std::cout << "checking special end condition for time attack" << std::endl;
    std::cout << "time elapsed: " << timeElapsed << std::endl;
    std::cout << "time remaining: " << maxtime_ - timeElapsed << std::endl;
    if(timeElapsed < maxtime_){
        return true;
    }
    else{
        return false;
    }
}