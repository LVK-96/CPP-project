#pragma once
#include <SFML/Graphics.hpp>
#include <tgmath.h>
#include <iostream>
#include <string>
#include <fstream>
#include "state.hpp"
#include "guiwindow.hpp"
#include "map.hpp"
/*Savemap menu gamestate class*/

class SaveMap : public State {
public:
	SaveMap(GUIWindow& guiWindow, Map map);
	~SaveMap() = default;
	
	SaveMap& operator= (const SaveMap& s) = default;
	SaveMap(const SaveMap& s) = default;
	
	virtual void draw();
	virtual bool update();
	virtual bool handleInput();

private:
	GUIWindow& guiWindow_;
	Map map_;
	sf::Text filepath_;
};