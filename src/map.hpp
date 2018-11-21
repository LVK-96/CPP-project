#pragma once
#include <vector>

class Map {
public:
    Map();

    std::vector<std::vector<int> > getMatrix() const;
    void setTile (int x, int y, int color); 
	int getTile(int x, int y) const;
protected:
    std::vector<std::vector<int> > matrix_;
};
