#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "map.hpp"
/*Virtual class. Classic and timeattack -gamemodes inherit this*/

class GameMode {
	public:
		GameMode() = default;
		GameMode(std::string name);
		virtual ~GameMode() = default; 
		GameMode& operator= (const GameMode& g) = default;
		GameMode(const GameMode& g) = default;

		virtual std::string getName() const;
		bool checkBaseEndCondition(Map map);
		virtual bool checkSpecialEndCondition(float timeElapsed);
		virtual float getMaxTime(){return 0.0;};
		virtual void addTime(){};

	protected:
		std::string name_;
};