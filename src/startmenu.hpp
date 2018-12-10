#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"
#include "mapmenu.hpp"
#include "scoregui.hpp"

class StartMenu: public State {
    public:
        StartMenu(GUIWindow& guiWindow);
        ~StartMenu(){};//no memory allocated with new - no memory needs to be deallocated with delete

        virtual void draw(const float dt); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual void update(const float dt);
        virtual bool handleInput(); // window event loop, close window or call startGame

        void startGame(); // add game to the state stack
		void readScore();
    private:
		GUIWindow& guiWindow_;
};
