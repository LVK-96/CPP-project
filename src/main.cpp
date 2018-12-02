#include "guiwindow.hpp"
#include "startmenu.hpp"

int main() {
   	GUIWindow gui = GUIWindow();
	StartMenu(&gui);
	gui.gameLoop();
    return 0;
}
