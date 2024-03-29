#include "savemap.hpp"


SaveMap::SaveMap(GUIWindow& guiWindow, Map map): guiWindow_(guiWindow), map_(map) {
	std::string save = "";
	filepath_.setString(save);
}

void SaveMap::draw() {
	std::vector<std::vector<int>> matrix = map_.getMatrix();
	sf::CircleShape shape(48.f, 8);
	sf::RectangleShape wallshape(sf::Vector2f(96.f, 96.f));
	const int distance = 100; //distance between dots
    const float height = sqrt(pow(distance,2.f));

	for (unsigned int i=0; i < matrix.size(); i++) {
    	for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == -1) {
				wallshape.setPosition(j*distance, i*height);
				wallshape.setFillColor(sf::Color(139, 69, 19)); //brown for walls
				guiWindow_.getWindow().draw(wallshape);
			}
			else {
		    	shape.setPosition(j*distance, i*height);
				if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
				else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
				else shape.setFillColor(sf::Color::Transparent);
	        	guiWindow_.getWindow().draw(shape);
			}
		}
	}
	
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);
	std::string save = "Filename(press esc to cancel): ";
	text.setString(save);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(10, 800);
	guiWindow_.getWindow().draw(text);
	

	std::string inputstr = filepath_.getString().toAnsiString();
	sf::Text userinput;
	userinput.setFont(font);
	userinput.setString(inputstr);
	userinput.setCharacterSize(24);
	userinput.setColor(sf::Color::Red);
	userinput.setPosition(350, 800);
	guiWindow_.getWindow().draw(userinput);
}

bool SaveMap::handleInput() {
	sf::Event event;
	//outer loop loops while there is no event and the inner loop catches it
	
	while (guiWindow_.getWindow().pollEvent(event)) {
		sf::String playerInput;

		if (event.type == sf::Event::Closed) {
				guiWindow_.getWindow().close();//if the window is closed the whole program should terminate
		}

		

		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == 8 && filepath_.getString().getSize() > 0) {
				 sf::String temp = filepath_.getString();
				 temp.erase(temp.getSize()-1, temp.getSize());
				 filepath_.setString(temp);
			}
			
			else if(event.text.unicode < 128) {
				playerInput +=event.text.unicode;
    			filepath_.setString(filepath_.getString() + playerInput);
			}
			
		}

		if (event.type == sf::Event::KeyPressed) {
			if(event.key.code == sf::Keyboard::Escape)
				return true;
			if (event.key.code == sf::Keyboard::Return) {
				//save into file and close mapeditor
				std::string savepath = "maps/" + filepath_.getString().toAnsiString() + ".txt";
				std::ofstream outfile(savepath.c_str());
				for (auto j : map_.getMatrix()) {
					for (auto i : j) {
						if (i == -1) {outfile<<'w';}
						else {outfile<<i;}
					}
					outfile<<std::endl;
				}
				outfile.close();

				std::ofstream maplist;
				maplist.open("maps/map_filenames.txt", std::ios::app);
				maplist<<filepath_.getString().toAnsiString() << std::endl;
				return true;
			}
		}
	}
	return false;
}

bool SaveMap::update() {return false;}

