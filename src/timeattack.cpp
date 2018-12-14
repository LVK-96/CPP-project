#include "timeattack.hpp"

TimeAttack::TimeAttack(std::string name) : name_(name), maxtime_(60){}

std::string TimeAttack::getName() const {return name_;}

bool TimeAttack::checkSpecialEndCondition(float timeElapsed){
    if(timeElapsed < maxtime_){
        return true;
    }
	
	return false;
}