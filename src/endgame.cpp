#include "startmenu.hpp"

 EndGame::EndGame(int points, std::string mapname, std::string modename, GUIWindow& guiwindow): points_(points), mapname_(mapname), modename_(modename), guiWindow_(guiwindow){}

bool EndGame::handleInput() {
	sf::Event event;
	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed){
			guiWindow_.getWindow().close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
					return true;//close endgame window if left mousebutton pressed
				}
		}

		if (event.type == sf::Event::KeyPressed)
		{
			return true;//close endgame window if any key pressed
		}
	}
	return false;
}

void EndGame::draw() {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	!font.loadFromFile("arial.ttf");
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
}

