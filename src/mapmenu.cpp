#include "mapmenu.hpp"


MapMenu::MapMenu(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	wincounter_ = 0;
	std::ifstream infile("maps/map_filenames.txt"); //map_filename is by default default.txt which is 8x8 of zeros
	std::string line;
	filearr_ = {}; //init an empty vector

	while(std::getline(infile, line)){

		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		filearr_.push_back(line);
	}

	initButtons();
}

MapMenu::~MapMenu() {
	//memory allocated with this

	for (auto it : mapbuttons_)
		delete it;
	delete nextbutton_;
	delete backbutton_;
}

void MapMenu::initButtons() {
	nextbutton_ = new Button("Next", 325, 600, 200, 50);
	backbutton_ = new Button("Back to menu", 100, 100, 150, 50);
	int j = 0;
	for(unsigned int i = 0; i < filearr_.size(); i++){
		if (j % 5 == 0)
			j = 0;
		mapbuttons_.push_back(new Button(filearr_[i], 325, 100 + 100 * j, 200, 75));
		j++;
	}
}


void MapMenu::startGame(std::string mapname) {
	guiWindow_.changeState(new ModeMenu(guiWindow_, mapname));
	//insert as second in stack will be first when this method returns
	/*we want to push the gamestate ontop of the STARTMENU - and we want to remove mapmenu from the stack - 
	we can do this only after returning from this function (and handleinput) - once back in game loop the top of the
	stack is popped - insert gameGUI as second in the stack*/

}

bool MapMenu::handleInput() {
	sf::Event event;

	while (guiWindow_.getWindow().pollEvent(event)) {
		
		if (event.type == sf::Event::Closed) {
			guiWindow_.getWindow().close();
			return true;
		}
               
			   
		if (event.type == sf::Event::MouseButtonPressed) {
    		if (event.mouseButton.button == sf::Mouse::Left) {
				for (int i = 0; i < 5; i++) {
					if(wincounter_ + i < filearr_.size()) {
						if (mapbuttons_[wincounter_ + i]->checkClick(event.mouseButton.x, event.mouseButton.y)) {
							startGame(filearr_[wincounter_+ i]);
							return true; 
						}
					}
				}
				
				if (nextbutton_->checkClick(event.mouseButton.x, event.mouseButton.y)) {
					if(wincounter_ + 5 < filearr_.size()){
						wincounter_ = wincounter_ + 5;
					}
					else {
						wincounter_ = 0;
					}
				}
				
				if (backbutton_->checkClick(event.mouseButton.x, event.mouseButton.y)) {
					return true;
				}
			}
		}
		
		if (event.type == sf::Event::KeyPressed) {
    		if (event.key.code == sf::Keyboard::A)
    		{
				if(wincounter_< filearr_.size()){
					//check that the index exists
					startGame(filearr_[wincounter_]);
					return true;
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}

            else if (event.key.code == sf::Keyboard::B)
    		{
				if(wincounter_ + 1 < filearr_.size()){
					startGame(filearr_[wincounter_ + 1]);
					return true;
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::C)
    		{
				if(wincounter_ + 2 < filearr_.size()){
					startGame(filearr_[wincounter_ + 2]);
					return true;
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::D)
    		{
				if(wincounter_ + 3 < filearr_.size()){
					startGame(filearr_[wincounter_ + 3]);
					return true;
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::E)
    		{
				if(wincounter_ + 4 < filearr_.size()){
					startGame(filearr_[wincounter_ + 4]);
					return true;
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if(event.key.code == sf::Keyboard::F){
				if(wincounter_ + 5 < filearr_.size()){
					wincounter_ = wincounter_ + 5;
				}
				else{
					wincounter_ = 0;
				}
			}
            else if (event.key.code == sf::Keyboard::Escape)
    		{
                //go back to startmenu
				return true;
    		}

		}
	}
    return false;
}

void MapMenu::draw() {
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);

	std::stringstream ss;
	ss << "Choose Map \n\n";
	
	for(unsigned int i = wincounter_; i < wincounter_ + 5 && i < filearr_.size(); i++){
		mapbuttons_[i]->drawButton(guiWindow_.getWindow());
	}

	text.setString(ss.str());
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	float xPos = 325;

	text.setPosition(xPos, 100);

	float ypos = 20;
	text.setPosition(xPos, ypos);
	
	nextbutton_->drawButton(guiWindow_.getWindow());
	backbutton_->drawButton(guiWindow_.getWindow());

	guiWindow_.getWindow().draw(text);
}

