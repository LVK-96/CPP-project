#include "guiwindow.hpp"
#include "startmenu.hpp"
#include <iostream>

int main() {
	GUIWindow gui;
	gui.pushState(new StartMenu(gui)); //we want to show this when it's created so we push it to the stack
	//dynamically aloocating the StartMenu so that GUIWindow default destructor can be used
	gui.gameLoop();
    return 0;
}
