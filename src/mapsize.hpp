#pragma once
#include "state.hpp"
#include "guiwindow.hpp"
#include "mapeditor.hpp"

class MapSize : public State {
public:
	MapSize(GUIWindow& guiWindow);
	~MapSize() = default;
	
	virtual void draw(const float dt);
	virtual bool handleInput();

private:
	GUIWindow& guiWindow_;		
};
