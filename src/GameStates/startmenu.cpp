#include "startmenu.hpp"

StartMenu::StartMenu(GUIWindow *guiWindow) {
    this->guiWindow=guiWindow;
}

StartMenu::startGame() {
    this->guiWindow->pushState(new GameGUI(this->guiWindow));
}