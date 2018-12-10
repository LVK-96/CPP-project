#pragma once
#include "guiwindow.hpp"

class MapEditor {
public:
	MapEditor(GUIWindow&);
	void DrawWall();
	void setSize();

private:
	Map map_;
	GUIWindow guiWindow_;	
};
