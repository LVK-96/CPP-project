#pragma once
#include <SFML/Graphics.hpp>
#include <tgmath.h>
#include "state.hpp"
#include "guiwindow.hpp"
#include "map.hpp"
#include "savemap.hpp"

class MapEditor : public State {
public:
	MapEditor(GUIWindow& guiWindow, int size);
	~MapEditor() = default;
	
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual bool handleInput();

private:
	GUIWindow& guiWindow_;
	Map map_;
};