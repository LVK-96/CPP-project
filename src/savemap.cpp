#include "savemap.hpp"

SaveMap::SaveMap(GUIWindow& guiWindow, Map map): guiWindow_(guiWindow), map_(map) {}

void SaveMap::draw(const float dt) {
	std::vector<std::vector<int>> matrix = map_.getMatrix();
	sf::CircleShape shape(48.f, 8);
	sf::RectangleShape wallshape(sf::Vector2f(96.f, 96.f));
	shape.setFillColor(sf::Color::Green);
	const int distance = 100; //distance between dots
    const float height = sqrt(pow(distance,2.f));

	for (unsigned int i=0; i < matrix.size(); i++) {
    	for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == -1) {
				std::cout << "Wall" << std::endl;
				wallshape.setPosition(j*distance, i*height);
				wallshape.setFillColor(sf::Color(139, 69, 19));//brown for walls
				guiWindow_.getWindow().draw(wallshape);
			}
			else {
		    	shape.setPosition(j*distance, i*height);
				if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
				else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
				else shape.setFillColor(sf::Color::Transparent);
	        	guiWindow_.getWindow().draw(shape);
			}
		}
	}
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
    	std::cout << "Error" << std::endl;
	}
	
	sf::Text text;
	text.setFont(font);
	std::string save = "Type filename";
	text.setString(save);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(10, 800);
}

bool SaveMap::handleInput() {
	sf::Event event;

	//outer loop loops while there is no event and the inner loop catches it
	sf::String playerInput;
	sf::Text playerText;
	
	while (guiWindow_.getWindow().pollEvent(event)) {
		if (event.type == sf::Event::TextEntered) {
    		playerInput += event.text.unicode;
    		playerText.setString(playerInput);
		}
		return false;
	}

}

void SaveMap::update(const float dt) {}

