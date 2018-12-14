#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"
#include "button.hpp"
#include "modemenu.hpp"
/*Mapmenu gamestate class*/


class MapMenu: public State {
    public:
        MapMenu(GUIWindow& guiWindow);
        ~MapMenu();
		MapMenu& operator= (const MapMenu& m) = default;
		MapMenu(const MapMenu& m) = default;

        virtual void draw(); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual bool handleInput(); // window event loop, close window or call startGame
        void startGame(std::string mapname); // add game to the state stack
		void initButtons();
		
    private:
		GUIWindow& guiWindow_;
        std::vector<std::string> filearr_;
        unsigned int wincounter_;
		std::vector<Button*> mapbuttons_;
		Button* nextbutton_;
		Button* backbutton_;
};
