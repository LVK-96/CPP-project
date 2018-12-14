#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"
#include "mapmenu.hpp"
#include "scoregui.hpp"
#include "mapeditor.hpp"
#include "button.hpp"

class StartMenu: public State {
    public:
        StartMenu(GUIWindow& guiWindow);
        ~StartMenu();

		StartMenu& operator= (const StartMenu& s) = default;
		StartMenu(const StartMenu& s) = default;
		
        virtual void draw(); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual bool handleInput(); // window event loop, close window or call startGame
        void startGame(); // add game to the state stack
    private:
		GUIWindow& guiWindow_;
		Button *playbutton_;
		Button *mapbutton_;
		Button *scorebutton_;
		Button *quitbutton_;
};
