#include "GUIWindow.hpp"

int main() {
   	GUIWindow gui = GUIWindow();
	StartMenu(&gui);
	gui.gameLoop();
    return 0;
}
