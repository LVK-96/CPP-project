#pragma once
#include <iostream>
#include <math.h>
#include <string>

#include "player.hpp"
#include "gamemode.hpp"
#include "map.hpp"
#include "game.hpp"

//forward declarations for GUIWindow and Game. Compiler needs this for memory allocation
class GUIWindow;
class Game;

class GameGUI : public State {
    public:
        GameGUI(GUIWindow& guiWindow);
        ~GameGUI();

        virtual void draw(const float dt); 
        virtual void update(const float dt);
        virtual void handleInput(); // window event loop, handle game inputs
        void drawTime(const float dt);
        void drawSelection(int x, int y);

	private:
		GUIWindow& guiWindow_;
		Game game_;
};
