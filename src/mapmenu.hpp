#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"

class MapMenu: public State {
    public:
        MapMenu(GUIWindow& guiWindow);
        ~MapMenu();

        virtual void draw(const float dt); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual void update(const float dt);
        virtual bool handleInput(); // window event loop, close window or call startGame

        void startGame(std::string mapname); // add game to the state stack
    private:
		GUIWindow& guiWindow_;
        std::vector<std::string> filearr_;
        unsigned int wincounter_;
};
