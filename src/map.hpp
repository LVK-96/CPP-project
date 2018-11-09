#pragma once
#include <vector>

class Map {
public:
    Map() = default;
    Map(std::vector<std::vector<int> > map);

    std::vector<std::vector<int> > getMatrix() const;
    int getColor(int x, int y) const;
    void setTile (int x, int y, int color); 
	int getTile(int x, int y) const;
protected:
    std::vector<std::vector<int> > matrix_;
};
