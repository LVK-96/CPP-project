#include "timeattack.hpp"

TimeAttack::TimeAttack(std::string name) : name_(name), maxtime_(100.0){}

bool TimeAttack::SpecialEndCondition(float dt){
    std::cout << "checking special end condition" << std::endl;
    if(dt > maxtime_){
        return true;
    }
    else{
        return false;
    }
}