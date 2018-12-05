#include "guiwindow.hpp"
#include "startmenu.hpp"
#include <iostream>

int main() {
	std::cout << "made it to main" << std::endl;
	GUIWindow gui;
	std::cout << "initialized guiwindow" << std::endl;
	StartMenu menu(&gui);
	std::cout << "initialized startmenu" << std::endl;
	gui.gameLoop();
    return 0;
}
