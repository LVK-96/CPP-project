#include "gamegui.hpp"
#include "iostream"
#include <math.h>
#include <string>
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
    const float height = sqrt(pow(distance,2.f));
		
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
	std::string timestr = "Time: " +  std::to_string(time);
	text.setString(timestr);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(10, 810);
	
	guiWindow_->getWindow().draw(text);


}

void GameGUI::handleInput() {
	std::cout << "entering handle input" << std::endl;
	std::vector<unsigned int> newCoords (4, 10000); //4 1k's in a vector
	sf::Event event;

	float dt = this->game_->getTime();

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error in loading font" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	std::string timestr = "Time: " +  std::to_string(dt);
	text.setString(timestr);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(10, 810);
	std::cout << timestr << std::endl;
	//guiWindow_->getWindow().draw(text);

	int counter = 0;
	//outer loop loops while there is no event and the inner loop catches it
	while (counter < 2){
		while (this->guiWindow_->getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				this->guiWindow_->getWindow().close();//if the window is closed the whole program should terminate
				}
			if (event.type == sf::Event::MouseButtonPressed)
			{
    			if (event.mouseButton.button == sf::Mouse::Left)
    			{
					//this loop is entered only once per mouse click event
					std::cout << "click number: " << counter + 1 << std::endl;
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
						counter++;
					}
					else{
						std::cout << "same tile pressed twice" << std::endl;
						counter++;
					}
    			}
			}
			dt = this->game_->getTime();
			timestr = "Time: " +  std::to_string(dt);
			text.setString(timestr);
			//std::cout << timestr << std::endl;
			guiWindow_->getWindow().draw(text);
		}
		if (this->game_->isAdjacent(newCoords[0], newCoords[1], newCoords[2], newCoords[3])) {
			std::cout << "are adjacent" << std::endl;
			this->game_->swapCoords(newCoords[0], newCoords[1], newCoords[2], newCoords[3]);
			return;
		}
	}
	std::cout << "invalid move" << std::endl;
	
}

void GameGUI::update(const float dt){}
