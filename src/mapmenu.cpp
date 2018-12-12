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
}

MapMenu::~MapMenu(){
    std::cout << "Map menu destructor called" << std::endl << "delete this probably not a good idea" << std::endl;
	//memory allocated with this
}




void MapMenu::startGame(std::string mapname) {
    guiWindow_.changeState(new GameGUI(guiWindow_, mapname)); //insert as second in stack will be first when this method returns
	/*we want to push the gamestate ontop of the STARTMENU - and we want to remove mapmenu from the stack - 
	we can do this only after returning from this function (and handleinput) - once back in game loop the top of the
	stack is popped - insert gameGUI as second in the stack*/

}

bool MapMenu::handleInput() {
	sf::Event event;
    bool ret = false;

	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed /*|| event.key.code == sf::Keyboard::Q*/)
               guiWindow_.getWindow().close();
		if (event.type == sf::Event::KeyPressed)
		{
    		if (event.key.code == sf::Keyboard::A)
    		{
				if(wincounter_< filearr_.size()){
					//check that the index exists
					std::cout <<"A pressed" << std::endl;
					std::cout << "set map: " << filearr_[wincounter_] << std::endl;
					startGame(filearr_[wincounter_]);
                	//set a map and start Game
					//startGame();//this may result to problems if the loops stays on
                	ret = true;
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
                	ret = true;
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
                	ret = true;
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
                	ret = true;
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
                	ret = true;
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
				ret = true;
    		}

		}
		//std::cout << "end of first loop" << std::endl;
	}
    return ret;
}

void MapMenu::draw(const float dt) {
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
	for(int i = wincounter_; i < wincounter_ + 5 && i < filearr_.size(); i++){
		ss << filearr_[i];
		ss << "\n\n";
	}
	if(filearr_.size() > 5){
		ss << "press f for next\n\n";
	}
	ss << "press q to go back"; 

	text.setString(ss.str());
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;

	text.setPosition(xPos, 100);

	float ypos = 100;
	text.setPosition(xPos, ypos);
	
	guiWindow_.getWindow().draw(text);
}

void MapMenu::update(const float dt){}
