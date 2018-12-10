#include "mapmenu.hpp"

MapMenu::MapMenu(GUIWindow& guiWindow): guiWindow_(guiWindow) {}

MapMenu::~MapMenu(){
    std::cout << "Map menu destructor called" << std::endl << "delete this probably not a good idea" << std::endl;
	//memory allocated with this
}

void MapMenu::startGame() {
    guiWindow_.pushState(new GameGUI(guiWindow_));
	/*we want to push the gamestate ontop of the startmenu in the stack not replace it*/
}

bool MapMenu::handleInput() {
	sf::Event event;
    bool ret = false;

	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed /*|| event.key.code == sf::Keyboard::Q*/)
               guiWindow_.getWindow().close();
		if (event.type == sf::Event::KeyPressed)
		{
    		if (event.key.code == sf::Keyboard::A)
    		{
				std::cout <<"A pressed" << std::endl;
                //set a map and start Game
				//startGame();//this may result to problems if the loops stays on
                 ret = true;
    		}
            if (event.key.code == sf::Keyboard::B)
    		{
				std::cout <<"B pressed" << std::endl;
                //set a map and start Game
				//startGame();//this may result to problems if the loops stays on
                ret = true;
    		}
            if (event.key.code == sf::Keyboard::Q)
    		{
                //go back to startmenu
				std::cout <<"Q pressed" << std::endl;
				ret = true;
    		}

		}
		std::cout << "end of first loop" << std::endl;
	}
    return ret;
}

void MapMenu::draw(const float dt) {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Choose Map \n\n"
					"press a to choose default \n\n"
					"press b to choose default\n\n"
					"press q to go back");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	guiWindow_.getWindow().draw(text);
}

void MapMenu::update(const float dt){}
