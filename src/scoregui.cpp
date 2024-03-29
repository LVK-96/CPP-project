#include "scoregui.hpp"


ScoreGUI::ScoreGUI(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	loadScores();
	backbutton_ =  new Button("Back", 325, 500, 150, 50);
	deletebutton_ = new Button("Delete", 500, 500, 150, 50);	
}

ScoreGUI::~ScoreGUI() {
	delete backbutton_;
	delete deletebutton_;
}

bool ScoreGUI::handleInput() {
	sf::Event event;
	while (guiWindow_.getWindow().pollEvent(event))
	{
         // "close requested" event: we close the window
		if (event.type == sf::Event::Closed){
			guiWindow_.getWindow().close();
			return true;
		}
		
		if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
					if (backbutton_->checkClick(event.mouseButton.x, event.mouseButton.y)) {
						return true;
					}
					
					if (deletebutton_->checkClick(event.mouseButton.x, event.mouseButton.y)) {deleteScores();}
				}
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if(event.key.code == sf::Keyboard::Escape) {
				return true;
			}
			
			if (event.key.code == sf::Keyboard::D) {
				deleteScores();
			}
		}
	}
	
	return false;
}

void ScoreGUI::draw() {

	//no loop? It runs in the guiwindow::Gameloop?
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setString(getStr());
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 325;
	text.setPosition(xPos, 100);

	backbutton_->drawButton(guiWindow_.getWindow());
	deletebutton_->drawButton(guiWindow_.getWindow());

	guiWindow_.getWindow().draw(text);
}

void ScoreGUI::loadScores() {
	scores.clear();
	std::string name;
	std::string score;
	std::ifstream myfile ("highscore.txt");
  	if (myfile.is_open()) {
    	while (std::getline(myfile,name, ' ') &&  std::getline(myfile,score)) {
			scores.push_back(std::make_pair(std::stoi(score), name));
		}
		sort(scores.begin(), scores.end());
    	myfile.close();
	}
}

void ScoreGUI::deleteScores() {
	std::ofstream ofs;
	ofs.open("highscore.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	loadScores();
}

std::string ScoreGUI::getStr() {
	std::string scorestr = "Highscores: \n\n";
	int i = 0;
	for (auto it = scores.rbegin(); it != scores.rend(); ++it)
    {
		if (i >= 10)
			break;
		scorestr += std::to_string(i + 1) + ". ";
        scorestr += (*it).second + ' ' + std::to_string((*it).first) + '\n'; 
		i++;
    }
	return scorestr;
}
