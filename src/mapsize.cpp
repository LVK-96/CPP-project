#include "mapsize.hpp"

MapSize::MapSize(GUIWindow& guiWindow): guiWindow_(guiWindow) {}

bool MapSize::handleInput() {
	sf::Event event;
	while (guiWindow_.getWindow().pollEvent(event)) {
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed) {
			std::cout << "window closed" << std::endl;
			guiWindow_.getWindow().close();
		}


		if (event.type == sf::Event::KeyPressed) {
    		if (event.key.code == sf::Keyboard::A) {
				std::cout <<"A pressed" << std::endl;
				guiWindow_.pushState(new MapEditor(guiWindow_, 8));
    		}
			
			if (event.key.code == sf::Keyboard::S) {
				std::cout <<"S pressed" << std::endl;
				//guiWindow_.pushState(new MapEditor(guiWindow_, 16));
    		}
			
			if (event.key.code ==sf::Keyboard::D) {
				std::cout <<"D pressed" << std::endl;
				//guiWindow_.pushState(new MapEditor(guiWindow_, 32));
			}
			
			if(event.key.code == sf::Keyboard::B) {
				std::cout << "B pressed" << std::endl;
				guiWindow_.popState();
				
			}
		}
	}
	return false;
}

void MapSize::draw(const float dt) {

	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("a 8x8 \n\n"
					"s 16x16 \n\n"
					"d 32x32\n\n"
					"press b to go back");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	guiWindow_.getWindow().draw(text);
}

void MapSize::update(const float dt){}


