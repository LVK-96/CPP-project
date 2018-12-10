#include "savemap.hpp"

SaveMap::SaveMap(GUIWindow& guiWindow, Map map): guiWindow_(guiWindow), map_(map) {}

void SaveMap::draw(const float dt) {
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
    	std::cout << "Error" << std::endl;
	}
	
	sf::Text text;
	text.setFont(font);
	text.setString("Type map name");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	guiWindow_.getWindow().draw(text);
}

bool SaveMap::handleInput() {
	sf::String playerInput;
	sf::Text playerText;
	
	while (guiWindow_.getWindow().pollEvent(event)) {
		
		if (event.type == sf::Event::Closed) {
				guiWindow_.getWindow().close();//if the window is closed the whole program should terminate
		}
	
		if (event.type == sf::Event::TextEntered) {
			playerInput +=event.text.unicode;
			playerText.setString(playerInput);
		}
	}
	
	return false;
}

void SaveMap::update(const float dt) {}