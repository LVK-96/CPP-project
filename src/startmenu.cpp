#include "startmenu.hpp"

StartMenu::StartMenu(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	button1_ = Button("Quit", 300, 300, 200, 100);
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
		if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
					if (button1_.checkClick(event.mouseButton.x, event.mouseButton.y))
						guiWindow_.getWindow().close();
				}
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
			
			if (event.key.code == sf::Keyboard::E) {
				std::cout <<"E pressed" << std::endl;
				guiWindow_.pushState(new MapSize(guiWindow_));
			}
			
			if (event.key.code == sf::Keyboard::C)
    		{
				std::cout <<"C pressed" << std::endl;
				guiWindow_.pushState(new ScoreGUI(guiWindow_));
				
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
					"press e to start map editor \n\n"
					"press q to quit");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	button1_.drawButton(&guiWindow_.getWindow());

	guiWindow_.getWindow().draw(text);
}

void StartMenu::update(const float dt){}
