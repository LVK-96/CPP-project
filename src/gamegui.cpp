#include "gamegui.hpp"


GameGUI::GameGUI(GUIWindow& guiWindow, std::string mapname, std::string modename): guiWindow_(guiWindow), mapname_(mapname) {
	correctmoveFlag_ = 0;
	Player p1;
	std::vector<Player> players;
	players.push_back(p1);

	GameMode *mode;

	if(modename == "default"){
		mode = new GameMode("Classic");
	}
	else if(modename == "timeattack"){
		mode = new TimeAttack("Time Attack");
	}
	else{
		mode = new GameMode("Classic");
	}
	
	std::stringstream ss;
	ss << "maps/" << mapname << ".txt"; //parse path
	Map map(loadMap(ss.str()));
	game_ = new Game(players, map, mode);

	//check if game has ended before any moves have been made
	availablemoves_ = game_->getGameMode()->checkBaseEndCondition(game_->getMap());
	
	musicBuffer_.loadFromFile("gamemusic.wav");
	music_.setBuffer(musicBuffer_);
	music_.play();
	music_.setLoop(true);
	matchBuffer_.loadFromFile("matchsound.wav");
	matchSound_.setBuffer(matchBuffer_);
}

GameGUI::~GameGUI() {
	delete game_;
}

std::vector<std::vector<int>> GameGUI::loadMap(std::string map_filename) {
	std::vector<std::vector<int>> temp(8, std::vector<int>(8,0));

	std::ifstream infile(map_filename);//map_filename is by default default.txt which is 8x8 of zeros
	std::string line;
	int x = 0;
	int y = 0;

	while(std::getline(infile, line)){
		line.resize(8);
		for(auto i = line.begin(); i != line.end(); i++){

			//read chars from line to matrix
			if(*i == 'w'){
				temp[x][y] = -1;
			}
			else if(*i == 'x'){
				temp[x][y] = 0;
			}
			else{
				temp[x][y] = 0;
			}
			y++;
		}
		x++;
		y = 0;
	}
	return temp;
}



void GameGUI::drawTime(const float time){
	
	int roundedtime = static_cast<int>(time);
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);
	std::string timestr = "Time Elapsed: " +  std::to_string(roundedtime);
	text.setString(timestr);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(10, 800);//old 10 810

	//draw a rectangle over the existing time
	sf::RectangleShape rect(sf::Vector2f(200, 100));
	rect.setPosition(10, 800);
	rect.setFillColor(sf::Color::Black);
	guiWindow_.getWindow().draw(rect);
	guiWindow_.getWindow().draw(text);
	guiWindow_.getWindow().display();//display command could probably be removed from guiWindow

	if(game_->getGameMode()->getName() == "Time Attack"){
			//draw time left
			drawTimeLeft(game_->getGameMode()->getMaxTime());
	}
}

void GameGUI::draw() {
	std::vector<std::vector<int>> matrix = game_->getMap().getMatrix();//should getMatrix or getMap return a reference
	sf::CircleShape shape(48.f, 8);
	sf::RectangleShape wallshape(sf::Vector2f(96.f, 96.f));
	shape.setFillColor(sf::Color::Green);
	const int distance = 100; //distance between dots
    const float height = sqrt(pow(distance,2.f));

	for (unsigned int i=0; i < matrix.size(); i++) {
    	for (unsigned int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == -1) {
				wallshape.setPosition(j*distance, i*height);
				wallshape.setFillColor(sf::Color(139, 69, 19));//brown for walls
				guiWindow_.getWindow().draw(wallshape);
			}
			else {
		    	shape.setPosition(j*distance, i*height);
				if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
				else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
				else if (matrix[i][j] == 5) shape.setFillColor(sf::Color::Magenta);
				else shape.setFillColor(sf::Color::Transparent);
	        	guiWindow_.getWindow().draw(shape);
			}
		}
	}
	
	//time
	sf::Time elapsed=clock_.getElapsedTime();
	float dt=elapsed.asSeconds();
	
	drawTime(dt);
	drawScore();
}

void GameGUI::drawScore() {
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	std::string scorestr = "Score: " +  std::to_string(game_->getScore());
	text.setString(scorestr);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(250, 800);
	
	guiWindow_.getWindow().draw(text);
	guiWindow_.getWindow().display();
}

void GameGUI::drawSelection(int x, int y) {
	sf::CircleShape shape(48.f, 8);
	const int distance = 100; //distance between dots
    const float height = sqrt(pow(distance,2.f));
	shape.setPosition(x*distance, y*height);
	sf::Color white = sf::Color::White;
	white.a = 100;//set opacity
	shape.setFillColor(white);
	guiWindow_.getWindow().draw(shape);
	guiWindow_.getWindow().display();
}

void GameGUI::drawTimeLeft(float maxtime) {

	float currenttime = game_->getTime();
	int roundedtime = static_cast<int>(maxtime - currenttime);
	

	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);
	std::string timestr = "Time Left: " +  std::to_string(roundedtime);
	text.setString(timestr);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	text.setPosition(500, 800);

	//draw a rectangle over the existing time
	sf::RectangleShape rect(sf::Vector2f(200, 100));
	rect.setPosition(500, 800);
	rect.setFillColor(sf::Color::Black);
	guiWindow_.getWindow().draw(rect);
	guiWindow_.getWindow().draw(text);
	guiWindow_.getWindow().display();//display command could probably be removed from guiWindow
}

bool GameGUI::handleInput() {
	correctmoveFlag_ = 0;
	std::vector<unsigned int> newCoords (4, 10000); //4 1k's in a vector
	sf::Event event;

	availablemoves_ = game_->getGameMode()->checkBaseEndCondition(game_->getMap());

	if(!availablemoves_){
		guiWindow_.changeState(new EndGame(game_->getScore(), mapname_, game_->getGameMode()->getName(), guiWindow_));
		return true;//close game and display endgame screen
	}

	float dt = game_->getTime();

	int counter = 0;
	//outer loop loops while there is no event and the inner loop catches it
	while (counter < 2){
		if(!game_->getGameMode()->checkSpecialEndCondition(dt)){
			guiWindow_.changeState(new EndGame(game_->getScore(), mapname_, game_->getGameMode()->getName(), guiWindow_));
			return true;//close game and display endgame screen
		}

		dt = game_->getTime();
		drawTime(dt);
		while (guiWindow_.getWindow().pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				guiWindow_.getWindow().close();
				return true;
				//guiWindow_.~GUIWindow();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
					//this loop is entered only once per mouse click event
					unsigned int clickX = (event.mouseButton.x / 100);
					unsigned int clickY = (event.mouseButton.y / 100);
					if (clickX > 7 || clickY > 7) {return false;}
					if(game_->getMap().getTile(clickX, clickY) != -1){
						//dont allow selecting walls
						if (newCoords[2] != clickX || newCoords[3] != clickY) {
						newCoords[0] = newCoords[2];
						newCoords[1] = newCoords[3];
						newCoords[2] = clickX;
						newCoords[3] = clickY;
						counter++;
						drawSelection(newCoords[2], newCoords[3]);
						}
						else {
							counter++;
						}
					}
    			}
			}
			
			if (event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					guiWindow_.changeState(new EndGame(game_->getScore(), mapname_, game_->getGameMode()->getName(), guiWindow_));
					return true;
				}
			}
		}
		
		if (game_->isAdjacent(newCoords[0], newCoords[1], newCoords[2], newCoords[3])) {
			if (game_->swapCoords(newCoords[0], newCoords[1], newCoords[2], newCoords[3]) ) {
				game_->getGameMode()->addTime();
				correctmoveFlag_ = 1;
				matchSound_.play();
				
			}
			return false;
		}
	}
	return false;
}

bool GameGUI::update() {
	sf::Event event;

	guiWindow_.getWindow().clear(sf::Color::Black);
	draw();
	guiWindow_.getWindow().display();
	
	if (correctmoveFlag_ == 0) {return false;}
	
	for (unsigned int i = 0; i < 10; i++) { 
		guiWindow_.getWindow().pollEvent(event);
		sf::sleep(sf::seconds(0.02));
	}
	
	while(game_->dropTiles()) {
		guiWindow_.getWindow().clear(sf::Color::Black);
		draw();
		guiWindow_.getWindow().display();
		
		for (unsigned int i = 0; i < 10; i++) {
			sf::sleep(sf::seconds(0.004));
			guiWindow_.getWindow().pollEvent(event);
		}
	}
	
	for (unsigned int i = 0; i < 10; i++) { 
		guiWindow_.getWindow().pollEvent(event);
		sf::sleep(sf::seconds(0.05));
	}
	
	game_->fillMap();
	guiWindow_.getWindow().clear(sf::Color::Black);
	draw();
	guiWindow_.getWindow().display();
	
	for (unsigned int i = 0; i < 10; i++) { 
		guiWindow_.getWindow().pollEvent(event);
		sf::sleep(sf::seconds(0.1));
	}
	
	if(game_->clearMatches()) {
		return true;
	}
	
	if(!(game_->getGameMode()->checkBaseEndCondition(game_->getMap()))) {
		guiWindow_.changeState(new EndGame(game_->getScore(), mapname_, game_->getGameMode()->getName(), guiWindow_));
		game_->saveScore();
	}
	
	return false;
}

