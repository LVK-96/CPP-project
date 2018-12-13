#include "mapmenu.hpp"

MapMenu::MapMenu(GUIWindow& guiWindow): guiWindow_(guiWindow){
	wincounter_ = 0;
	std::ifstream infile("maps/map_filenames.txt");//map_filename is by default default.txt which is 8x8 of zeros
	std::string line;
	filearr_ = {};//init an empty vector

	while(std::getline(infile, line)){

		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		std::cout << line.size() << std::endl;
		filearr_.push_back(line);
	}

	std::cout << "arr 0: " << std::endl;
	std::cout << filearr_[0] << std::endl;

	std::cout << "arr 1: " << std::endl;
	std::cout << filearr_[1] << std::endl;
	initButtons();
}

MapMenu::~MapMenu() {
    std::cout << "Map menu destructor called" << std::endl;
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
	for(int i = 0; i < filearr_.size(); i++){
		if (j % 5 == 0)
			j = 0;
		mapbuttons_.push_back(new Button(filearr_[i], 325, 100 + 100 * j, 200, 75));
		j++;
	}
}


void MapMenu::startGame(std::string mapname) {
    guiWindow_.changeState(new GameGUI(guiWindow_, mapname, "timeattack")); //insert as second in stack will be first when this method returns
	/*we want to push the gamestate ontop of the STARTMENU - and we want to remove mapmenu from the stack - 
	we can do this only after returning from this function (and handleinput) - once back in game loop the top of the
	stack is popped - insert gameGUI as second in the stack*/

}

bool MapMenu::handleInput() {
	sf::Event event;

	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed /*|| event.key.code == sf::Keyboard::Q*/)
               guiWindow_.getWindow().close();
		if (event.type == sf::Event::MouseButtonPressed) {
    		if (event.mouseButton.button == sf::Mouse::Left) {
				for (int i = 0; i < 6; i++) {
					if(wincounter_ + i< filearr_.size()) {
						if (mapbuttons_[wincounter_ + i]->checkClick(event.mouseButton.x, event.mouseButton.y))
							startGame(filearr_[wincounter_+ i]);
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
					std::cout <<"A pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_] << std::endl;
					startGame(filearr_[wincounter_]);
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}

            else if (event.key.code == sf::Keyboard::B)
    		{
				if(wincounter_ + 1 < filearr_.size()){
					std::cout <<"B pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_ + 1] << std::endl;
					startGame(filearr_[wincounter_ + 1]);
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::C)
    		{
				if(wincounter_ + 2 < filearr_.size()){
					std::cout <<"C pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_ + 2] << std::endl;
					startGame(filearr_[wincounter_ + 2]);
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::D)
    		{
				if(wincounter_ + 3 < filearr_.size()){
					std::cout <<"D pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_ + 3] << std::endl;
					startGame(filearr_[wincounter_ + 3]);
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
				}
    		}
			else if (event.key.code == sf::Keyboard::E)
    		{
				if(wincounter_ + 4 < filearr_.size()){
					std::cout <<"E pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_ + 4] << std::endl;
					startGame(filearr_[wincounter_ + 4]);
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
            else if (event.key.code == sf::Keyboard::Q)
    		{
                //go back to startmenu
				std::cout <<"Q pressed" << std::endl;
				return true;
    		}

		}
		//std::cout << "end of first loop" << std::endl;
	}
    return false;
}

void MapMenu::draw() {
	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);

	std::stringstream ss;
	ss << "Choose Map \n\n";
	int j = 0;
	for(unsigned int i = wincounter_; i < wincounter_ + 5 && i < filearr_.size(); i++){
		mapbuttons_[i]->drawButton(&guiWindow_.getWindow());
		//ss << filearr_[i];
		//ss << "\n\n";
	}
	/*if(filearr_.size() > 5){
		ss << "press f for next\n\n";
	}
	ss << "press q to go back";*/

	text.setString(ss.str());
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	float xPos = 325;

	text.setPosition(xPos, 100);

	float ypos = 20;
	text.setPosition(xPos, ypos);
	
	nextbutton_->drawButton(&guiWindow_.getWindow());
	backbutton_->drawButton(&guiWindow_.getWindow());

	guiWindow_.getWindow().draw(text);
}

