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

    private:
    bool paused;
    std::vector<Player> players_;
    Map map_;
    GameMode mode_;
};
