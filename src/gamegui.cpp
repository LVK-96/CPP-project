#include "gamegui.hpp"
#include "iostream"
GameGUI::GameGUI(GUIWindow *gui, Game *g) {
	guiWindow_ = gui;	
	game_ = g;
}

GameGUI::~GameGUI(){
	delete this;//memory allocated with new
}

void GameGUI::draw(const float time) {
	std::vector<std::vector<int>> matrix = this->game_->getMap().getMatrix();//should getMatrix or getMap return a reference
	sf::CircleShape shape(48.f, 8);
	shape.setFillColor(sf::Color::Green);
	const int distance = 100; //distance between dots
    const float height = std::sqrt(std::pow(distance,2.f));
		
	for (unsigned int i=0; i < matrix.size(); i++){
    	for (unsigned int j = 0; j < matrix[i].size(); j++) {
		    shape.setPosition(j*distance, i*height);
			if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
			else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
			else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
			else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
			else shape.setFillColor(sf::Color::Transparent);
	        guiWindow_->getWindow().draw(shape);
			}
		}

	//time

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error in loading font" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	std::string timestr = str(time);
	text.setString(timestr);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(10, 10);
	
	guiWindow_->window_.draw(text);


}

void GameGUI::handleInput(const float time) {
	std::vector<unsigned int> newCoords (4, 10000); //4 1k's in a vector
	sf::Event event;
	while (this->guiWindow->window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->guiWindow->window_.close();//if the window is closed the whole program should terminate
		if (event.type == sf::Event::MouseButtonPressed)
		{
    		if (event.mouseButton.button == sf::Mouse::Left)
    		{
				unsigned int clickX = (event.mouseButton.x / 100);
				unsigned int clickY = (event.mouseButton.y / 100);
				if (newCoords[2] != clickX || newCoords[3] != clickY) {
					newCoords[0] = newCoords[2];
					newCoords[1] = newCoords[3];
					newCoords[2] = clickX;
					newCoords[3] = clickY;
		    		std::cout << "the left button was pressed" << std::endl;
		    		std::cout << "mouse x: " << newCoords[2] << std::endl;
		    		std::cout << "mouse y: " << newCoords[3] << std::endl;
				}
    		}
		}
		if (this->game_->isAdjacent(newCoords[0], newCoords[1], newCoords[2], newCoords[3])) {
			this->game_->swapCoords(newCoords[0], newCoords[1], newCoords[2], newCoords[3]);
			return
		}
	}

}
