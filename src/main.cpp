#include "guiwindow.hpp"
#include "startmenu.hpp"
#include <iostream>

int main() {
	GUIWindow gui;
	StartMenu menu(gui);
	gui.gameLoop();
    return 0;
}
