#include "scoregui.hpp"

ScoreGUI::ScoreGUI(GUIWindow& guiWindow): guiWindow_(guiWindow) {
	loadScores();
	
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
			if (event.key.code == sf::Keyboard::D) {
				std::cout << "D pressed - deleting highscores" << std::endl;
				deleteScores();
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
	text.setString(getStr());
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);

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
	else std::cout << "Unable to open file"; 
	
}

void ScoreGUI::deleteScores() {
	std::ofstream ofs;
	ofs.open("highscore.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	loadScores();
}

std::string ScoreGUI::getStr() {
	std::string scorestr = "Highscores (press q to quit, d to delete): \n\n";
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
void ScoreGUI::update(const float dt){}
