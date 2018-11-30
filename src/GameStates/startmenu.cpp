#include "startmenu.hpp"

StartMenu::StartMenu(GUIWindow *guiWindow) {
    this->guiWindow=guiWindow;
    sf::Vector2f pos=sf::Vector2f(this->guiWindow->window_.getSize()); // set view size to window size
    this->view_.setSize(pos);
}

StartMenu::startGame() {
    this->guiWindow->pushState(new GameGUI(this->guiWindow));
}