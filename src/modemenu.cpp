#include "modemenu.hpp"

ModeMenu::ModeMenu(GUIWindow& guiWindow, std::string mapname): guiWindow_(guiWindow), mapname_(mapname){

	initButtons();

}

ModeMenu::~ModeMenu() {
	//memory allocated with this
	for (auto it : mapbuttons_)
		delete it;
	delete backbutton_;
}

void ModeMenu::initButtons() {
	backbutton_ = new Button("Back to menu", 100, 100, 150, 50);
    mapbuttons_.push_back(new Button("Classic", 325, 100, 200, 75));
    mapbuttons_.push_back(new Button("Time Attack", 325, 200, 200, 75));
}


void ModeMenu::startGame(std::string modename) {
    guiWindow_.changeState(new GameGUI(guiWindow_, mapname_, modename));
	//insert as second in stack will be first when this method returns
	/*we want to push the gamestate ontop of the STARTMENU - and we want to remove mapmenu from the stack - 
	we can do this only after returning from this function (and handleinput) - once back in game loop the top of the
	stack is popped - insert gameGUI as second in the stack*/

}

bool ModeMenu::handleInput() {
	sf::Event event;

	while (guiWindow_.getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			guiWindow_.getWindow().close();
			return true;
		}
               
			   
		if (event.type == sf::Event::MouseButtonPressed) {
    		if (event.mouseButton.button == sf::Mouse::Left) {	
				if (mapbuttons_[0]->checkClick(event.mouseButton.x, event.mouseButton.y)){
                    startGame("classic");
					return true;
                }
                if (mapbuttons_[1]->checkClick(event.mouseButton.x, event.mouseButton.y)){
                    startGame("timeattack");
					return true;
                }
				if (backbutton_->checkClick(event.mouseButton.x, event.mouseButton.y)) {
					return true;
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q)
    		{
                //go back to startmenu
				return true;
    		}

		}
	}
    return false;
}

void ModeMenu::draw() {
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);

	std::stringstream ss;
	ss << "Choose Mode \n\n";
	
	mapbuttons_[0]->drawButton(guiWindow_.getWindow());
    mapbuttons_[1]->drawButton(guiWindow_.getWindow());
	
	

	text.setString(ss.str());
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	float xPos = 325;

	text.setPosition(xPos, 100);

	float ypos = 20;
	text.setPosition(xPos, ypos);
	
	backbutton_->drawButton(guiWindow_.getWindow());

	guiWindow_.getWindow().draw(text);
}

