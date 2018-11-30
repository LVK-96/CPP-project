#include "startmenu.hpp"
#include "game.hpp"

StartMenu::StartMenu(GUIWindow *guiWindow) {
    this->guiWindow=guiWindow;
}

StartMenu::startGame() {
    Player p1;
	std::vector<Player> players;
	players.push_back(p1);

	Map map(std::vector<std::vector<int> >(8, std::vector<int>(8,0)));

    game=new Game(players,map, mode,window_);

    this->guiWindow->pushState(new GameGUI(this->guiWindow));
}