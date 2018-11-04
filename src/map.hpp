#pragma once
#include <vector>

class Map {
    public:
    Map() = default;
    Map(std::vector<std::vector<int> > map);
    std::vector<std::vector<int> > getMatrix() const;
    void setMatrix (int x, int y); 

    private:
    std::vector<std::vector<int> > matrix_;
};