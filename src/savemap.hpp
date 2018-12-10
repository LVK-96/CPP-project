#pragma once
#include <SFML/Graphics.hpp>
#include <tgmath.h>
#include <iostream>
#include <string>
#include <fstream>
#include "state.hpp"
#include "guiwindow.hpp"
#include "map.hpp"

class SaveMap : public State {
public:
	SaveMap(GUIWindow& guiWindow, Map map);
	~SaveMap() = default;
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual bool handleInput();

private:
	GUIWindow& guiWindow_;
	Map map_;
	sf::Text filepath_;
};