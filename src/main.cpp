#include "guiwindow.hpp"
#include "startmenu.hpp"

int main() {
	GUIWindow gui;
	StartMenu menu(&gui);
	gui.gameLoop();
    return 0;
}
