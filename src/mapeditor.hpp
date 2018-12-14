#pragma once
#include <SFML/Graphics.hpp>
#include <tgmath.h>
#include "state.hpp"
#include "guiwindow.hpp"
#include "map.hpp"
#include "savemap.hpp"
/*Mapeditor gamestate class*/

class MapEditor : public State {
	public:
		MapEditor(GUIWindow& guiWindow, int size);
		~MapEditor() = default;
		MapEditor& operator= (const MapEditor& m) = default;
		MapEditor(const MapEditor& m) = default;
	
		virtual void draw();
		virtual bool handleInput();

	private:
		GUIWindow& guiWindow_;
		Map map_;
};
