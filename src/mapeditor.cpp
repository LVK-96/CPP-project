#include "mapeditor.hpp"


MapEditor::MapEditor(GUIWindow& guiWindow, int size): guiWindow_(guiWindow) {
	std::vector<std::vector<int> > temp(size, std::vector<int>(size,0));
	Map map(temp);
	map_ = map;
}

void MapEditor::draw() {
	std::vector<std::vector<int>> matrix = map_.getMatrix();
	sf::CircleShape shape(48.f, 8);
	sf::RectangleShape wallshape(sf::Vector2f(96.f, 96.f));
	const int distance = 100; //distance between dots
    const float height = sqrt(pow(distance,2.f));

	for (unsigned int i=0; i < matrix.size(); i++) {
    	for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == -1) {
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
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	std::string save = "Press S to save";
	text.setString(save);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(10, 800);
	guiWindow_.getWindow().draw(text);
}

bool MapEditor::handleInput() {
	std::vector<unsigned int> newCoords (4, 10000);
	sf::Event event;

	//outer loop loops while there is no event and the inner loop catches it
	while (guiWindow_.getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
				guiWindow_.getWindow().close(); //if the window is closed the whole program should terminate
				return true;
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				unsigned int clickX = (event.mouseButton.x / 100);
				unsigned int clickY = (event.mouseButton.y / 100);
				if (clickX > 7 || clickY > 7) {return false;}
				
				if (map_.getTile(clickX, clickY) == -1) {
					std::vector<std::vector<int> > temp = map_.getMatrix();
					temp[clickY][clickX] = 0;
					map_.setMatrix(temp);
				}
				
				else {map_.setTile(clickX, clickY, -1);}
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::S) {
				guiWindow_.pushState(new SaveMap(guiWindow_, map_));
			}
			if (event.key.code == sf::Keyboard::Escape) {
				return true;
			}

		}
	}
	return false;	
}


