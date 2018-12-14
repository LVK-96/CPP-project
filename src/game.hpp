#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "map.hpp"
#include "player.hpp"
#include "gamemode.hpp"
#include "guiwindow.hpp"
#include "guiwindow.hpp"
/*Game backend class, implements game logic*/

class Game {
public:
    Game() = default;
    Game(std::vector<Player> players, Map map, GameMode *mode);
	~Game();
	Game& operator=(const Game& g) = default; 
	Game(const Game& g) = default;
	
    void updateMap();
    void checkMove();
    void tickGame();
    std::pair<int, int> checkX(int x, int y) const;
    std::pair <int, int> checkY(int x, int y) const;
    bool isAdjacent(int x1, int y1, int x2, int y2) const;
    bool clearMatches();
    bool dropTiles();
	void fillMap();
    void printMap() const;
    bool swapCoords(int x1, int y1, int x2, int y2);
    Map getMap();
	float getTime();
	void addScore(int matches);
	int getScore();
	void saveScore();
	void specialEffect5(int color1, int color2);
    GameMode *getGameMode(){return mode_;}

private:
    bool paused;
    std::vector<Player> players_;
    Map map_;
    GameMode *mode_;
	sf::Clock clock_;
	int score_;
};
