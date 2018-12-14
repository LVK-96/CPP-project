#include "startmenu.hpp"


 EndGame::EndGame(int points, std::string mapname, std::string modename, GUIWindow& guiwindow): points_(points), mapname_(mapname), modename_(modename), guiWindow_(guiwindow){
	std::string save = "";
	filepath_.setString(save);

}

bool EndGame::handleInput() {
	sf::Event event;
	//outer loop loops while there is no event and the inner loop catches it
	
	while (guiWindow_.getWindow().pollEvent(event)) {
		sf::String playerInput;

		if (event.type == sf::Event::Closed) {
				guiWindow_.getWindow().close();//if the window is closed the whole program should terminate
		}

		

		if (event.type == sf::Event::TextEntered) {
			if(event.text.unicode >= 32 && event.text.unicode < 127) {
				playerInput += event.text.unicode;
    			filepath_.setString(filepath_.getString() + playerInput);
			}
			else if (event.text.unicode == 8 && filepath_.getString().getSize() > 0) {
				 sf::String temp = filepath_.getString();
				 temp.erase(temp.getSize()-1, temp.getSize());
				 filepath_.setString(temp);
			}
			
		}

		if (event.type == sf::Event::KeyPressed) {
			if(event.key.code == sf::Keyboard::Escape)
				return true;
			if (event.key.code == sf::Keyboard::Return) {
				std::string playername = filepath_.getString().toAnsiString();
				saveScore(playername);
				return true;
			}
		}
	}
	return false;
}

void EndGame::draw() {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
    std::stringstream ss;
    ss << "Game ended\n\nMap: "+ mapname_ +"\n\nGame Mode: " + modename_ + "\n\nScore: ";
    ss << points_;
	text.setString(ss.str());
	text.setCharacterSize(44);
	text.setColor(sf::Color::Red);
	float xPos = 200;
	text.setPosition(xPos, 200);
	guiWindow_.getWindow().draw(text);

	sf::Text text2;
	text2.setFont(font);
	std::string save = "Input your name: ";
	text2.setString(save);
	text2.setCharacterSize(24);
	text2.setColor(sf::Color::Red);
	text2.setPosition(10, 800);
	guiWindow_.getWindow().draw(text2);
	
	std::string inputstr = filepath_.getString().toAnsiString(); //not smart but fixes a bug
	sf::Text text3;
	text3.setFont(font);
	text3.setString(inputstr);
	text3.setCharacterSize(24);
	text3.setColor(sf::Color::Red);
	text3.setPosition(200, 800);
	guiWindow_.getWindow().draw(text3);
}

void EndGame::saveScore(std::string name) {
	std::ofstream myfile;
  	myfile.open ("highscore.txt", std::ofstream::app);
  	myfile << name << " " << std::to_string(points_) << "\n";
  	myfile.close();
}
