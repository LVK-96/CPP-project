#include "startmenu.hpp"

StartMenu::StartMenu(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	
}

bool StartMenu::handleInput() {
	sf::Event event;
	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed){
			std::cout << "window closed" << std::endl;
			guiWindow_.getWindow().close();
		}

               
		if (event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::Q)
			{
				std::cout << "Q pressed closing window" << std::endl;
				guiWindow_.getWindow().close();
			}

    		if (event.key.code == sf::Keyboard::A)
    		{
				std::cout <<"A pressed" << std::endl;
				guiWindow_.pushState(new MapMenu(guiWindow_));//call the map menu
    		}

			if (event.key.code == sf::Keyboard::B)
    		{
				std::cout <<"B pressed" << std::endl;
    		}
			if (event.key.code == sf::Keyboard::C)
    		{
				std::cout <<"C pressed" << std::endl;
				readScore();
				
    		}
		}
	}
	return false;
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
	
	guiWindow_.getWindow().draw(text);
}

void StartMenu::readScore() {
	std::string line;
	std::ifstream myfile ("highscore.txt");
  	if (myfile.is_open()) {
    	while ( getline (myfile,line) ) {
      		std::cout << line << '\n';
		}
    	myfile.close();
	}
	else std::cout << "Unable to open file"; 
}

void StartMenu::update(const float dt){}
