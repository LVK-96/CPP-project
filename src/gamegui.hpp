#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>

#include "guiwindow.hpp"
#include "player.hpp"
#include "gamemode.hpp"
#include "map.hpp"
#include "game.hpp"

//forward declarations for GUIWindow and Game. Compiler needs this for memory allocation
class GUIWindow;
class Game;

class GameGUI : public State {
    public:
        GameGUI(GUIWindow& guiWindow, std::string mapname);
        ~GameGUI() = default;

        virtual void draw(const float dt); 
        virtual void update(const float dt);
        virtual bool handleInput(); // window event loop, handle game inputs
        void drawTime(const float dt);
		void drawScore();
        void drawSelection(int x, int y);
        std::vector<std::vector<int>> loadMap(std::string map_filename);

	private:
		GUIWindow& guiWindow_;
		Game game_;
};
