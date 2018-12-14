#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
/*Represents the map, map objects are owned by game objects*/

class Map {
	public:
		Map() = default;
		Map(std::vector<std::vector<int>>);
		std::vector<std::vector<int> > getMatrix() const;
		bool setTile (int x, int y, int color); 
		int getTile(int x, int y) const;
		void setMatrix(std::vector<std::vector<int> > matrix);

	protected:
		std::vector<std::vector<int> > matrix_;
};