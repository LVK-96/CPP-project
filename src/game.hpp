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
    std::pair<int, int> checkX(Map map, int x, int y) const;
    std::pair <int, int> checkY(Map map, int x, int y) const;
    bool isAdjacent(int x1, int y1, int x2, int y2) const;
    void removeX(int x, int y, std::pair<int, int> matching, Map& map) const;
    void removeY(int x, int y, std::pair<int, int> matching, Map& map) const;
    void printMap(Map map) const;

    private:
    bool paused;
    std::vector<Player> players_;
    Map map_;
    GameMode mode_;
};
