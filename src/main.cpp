#include "guiwindow.hpp"
#include "startmenu.hpp"
/*Main function creates a GUIWindow object and starts game loop.*/

int main() {
	GUIWindow gui;
	gui.pushState(new StartMenu(gui)); //we want to show this when it's created so we push it to the stack
	gui.gameLoop();
    return 0;
}
