#pragma once
#include <vector>
#include "map.hpp"
#include "player.hpp"
#include "gamemode.hpp"

class Game {
public:
    Game() = default;
    Game(std::vector<Player> players, Map map, GameMode mode);

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
    void swapCoords(int x1, int y1, int x2, int y2);

private:
    bool paused;
    std::vector<Player> players_;
    Map map_;
    GameMode mode_;
};
