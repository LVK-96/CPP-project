#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"
#include "button.hpp"

class ModeMenu: public State {
    public:
        ModeMenu(GUIWindow& guiWindow, std::string mapname);
        ~ModeMenu();

		ModeMenu& operator= (const ModeMenu& m) = default;
		ModeMenu(const ModeMenu& m) = default;

        virtual void draw(); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual bool handleInput(); // window event loop, close window or call startGame
        void startGame(std::string mapname); // add game to the state stack
		void initButtons();
    private:

        std::string mapname_;
		GUIWindow& guiWindow_;
		std::vector<Button*> mapbuttons_;
		Button* nextbutton_;
		Button* backbutton_;
};
