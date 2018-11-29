#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class GUIWindow {
    public:
    void draw(std::vector<std::vector<int> > matrix) const;
	std::vector<unsigned int> getInput(std::vector<std::vector<int> > matrix);
};
