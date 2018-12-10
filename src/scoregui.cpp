#include "scoregui.hpp"

ScoreGUI::ScoreGUI(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	std::string line;
	scorestr = "";
	std::ifstream myfile ("highscore.txt");
  	if (myfile.is_open()) {
    	while ( getline (myfile,line) ) {
      		scorestr += line + '\n';
		}
    	myfile.close();
	}
	else std::cout << "Unable to open file"; 

}


bool ScoreGUI::handleInput() {
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
				std::cout << "Q pressed closing highscore" << std::endl;
				guiWindow_.popState();
			}
		}
	}
	return false;
}

void ScoreGUI::draw(const float dt) {

	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString(scorestr);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	guiWindow_.getWindow().draw(text);
}
void ScoreGUI::update(const float dt){}
