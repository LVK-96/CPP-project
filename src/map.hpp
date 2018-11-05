#pragma once
#include <vector>

class Map {
    public:
    Map() = default;
    Map(std::vector<std::vector<int> > map);
    std::vector<std::vector<int> > getMatrix() const;
    int getColor(int x, int y) const;
    void setMatrix (int x, int y, int color); 

    private:
    std::vector<std::vector<int> > matrix_;
};