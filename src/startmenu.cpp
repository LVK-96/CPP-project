#include "startmenu.hpp"


StartMenu::StartMenu(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	playbutton_ =  new Button("Play", 325, 100, 150, 50);
	mapbutton_ = new Button("Map Editor", 325, 200, 150, 50);
	scorebutton_ = new Button("Highscores", 325, 300, 150, 50);
	quitbutton_ = new Button("Quit", 325, 400, 150, 50);
}

StartMenu::~StartMenu() {
	delete playbutton_;
	delete mapbutton_;
	delete scorebutton_;
	delete quitbutton_;
}

bool StartMenu::handleInput() {
	sf::Event event;
	while (guiWindow_.getWindow().pollEvent(event)) {
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed){
			guiWindow_.getWindow().close();
			return true;
		}
		
		if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
					if (playbutton_->checkClick(event.mouseButton.x, event.mouseButton.y))
						guiWindow_.pushState(new MapMenu(guiWindow_));
					if (mapbutton_->checkClick(event.mouseButton.x, event.mouseButton.y))
						guiWindow_.pushState(new MapEditor(guiWindow_, 8));
					if (scorebutton_->checkClick(event.mouseButton.x, event.mouseButton.y))
						guiWindow_.pushState(new ScoreGUI(guiWindow_));
					if (quitbutton_->checkClick(event.mouseButton.x, event.mouseButton.y))
						guiWindow_.getWindow().close();
				}
		}

		if (event.type == sf::Event::KeyPressed) {

			if(event.key.code == sf::Keyboard::Escape)
			{

				guiWindow_.getWindow().close();
			}

    		if (event.key.code == sf::Keyboard::A) {
				guiWindow_.pushState(new MapMenu(guiWindow_));//call the map menu
    		}
			
			if (event.key.code == sf::Keyboard::E) {
				guiWindow_.pushState(new MapEditor(guiWindow_, 8));
			}
			
			if (event.key.code == sf::Keyboard::C) {
				guiWindow_.pushState(new ScoreGUI(guiWindow_));
				
    		}
		}
	}
	return false;
}

void StartMenu::draw() {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setString("press a to start game \n\n"
					"press b to configure settings \n\n"
					"press c to view highscores\n\n"
					"press e to start map editor \n\n"
					"press q to quit");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

	playbutton_->drawButton(guiWindow_.getWindow());
	mapbutton_->drawButton(guiWindow_.getWindow());
	scorebutton_->drawButton(guiWindow_.getWindow());
	quitbutton_->drawButton(guiWindow_.getWindow());
}
