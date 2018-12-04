#include "startmenu.hpp"
#include "game.hpp"

StartMenu::StartMenu(GUIWindow *guiWindow) {
    guiWindow_ = guiWindow;
	guiWindow_->pushState(this); //we want to show this when it's created so we push it to the stack
}

void StartMenu::startGame() {
    Player p1;
	std::vector<Player> players;
	players.push_back(p1);
	GameMode mode;

	Map map(std::vector<std::vector<int> >(8, std::vector<int>(8,0)));

    Game* game=new Game(players,map, mode);

    guiWindow_->changeState(new GameGUI(guiWindow_, &game));
}

void StartMenu::handleInput(const float dt) {
	sf::Event event;

	while (guiWindow_->window_.pollEvent(event))
	{
         // "close requested" event: we close the window
		 if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Q)
               window.close();
		if (event.type == sf::Event::KeyPressed)
		{
    		if (event.key.code == sf::Keyboard::A)
    		{
				std::cout <<"A pressed" << std::endl;
				startGame();//this may result to problems if the loops stays on
    		}
		}
	}
}

void StartMenu::draw(const float dt) {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("press a to start game \n\n"
					"press b to configure settings \n\n"
					"press c to view highscores\n\n"
					"press q to quit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);
	
	guiWindow_->window_.draw(text);
}


