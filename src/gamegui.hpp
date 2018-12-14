#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Audio.hpp>

#include "guiwindow.hpp"
#include "player.hpp"
#include "gamemode.hpp"
#include "map.hpp"
#include "game.hpp"
#include "endgame.hpp"
#include "timeattack.hpp"

//forward declarations for GUIWindow and Game. Compiler needs this for memory allocation
class GUIWindow;
class Game;

class GameGUI : public State {
    public:
        GameGUI(GUIWindow& guiWindow, std::string mapname, std::string modename);
        ~GameGUI();
		
		GameGUI& operator= (const GameGUI& g) = default;
		GameGUI(const GameGUI& g) = default;

        virtual void draw(); 
        virtual bool update();
        virtual bool handleInput(); // window event loop, handle game inputs
        void drawTime(const float dt);
		void drawScore();
        void drawSelection(int x, int y);
		void drawTimeLeft(float maxtime);
        std::vector<std::vector<int>> loadMap(std::string map_filename);

	private:
		GUIWindow& guiWindow_;
		Game *game_;
        std::string mapname_;
        bool availablemoves_;

		sf::Sound music_;
		sf::SoundBuffer musicBuffer_;
		sf::Sound matchSound_;
		sf::SoundBuffer matchBuffer_;
		sf::Clock clock_;
		
		int correctmoveFlag_;
};
