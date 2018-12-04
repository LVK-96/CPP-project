/*#pragma once
#include <string>
#include "game.hpp"
#include "guiwindow.hpp"

class TileMatching {
public:
    TileMatching();

    Game getGame() const;
    std::string getStatus() const;
    void setStatus(std::string new_status);
    void setGame(Game new_game);
    void runGame();

private:
    std::string status_;
    Game game_;
    GUIWindow window_;
};
*/