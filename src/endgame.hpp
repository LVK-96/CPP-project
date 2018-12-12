#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "state.hpp"

class EndGame: public State {
    public:
        EndGame(int points, std::string mapname, std::string modename, GUIWindow& guiwindow);
        ~EndGame() = default;

        virtual void draw(const float dt); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual bool handleInput(); // window event loop, close window or call startGame
        void update(const float dt);


        void startGame(); // add game to the state stack
    private:
        GUIWindow& guiWindow_;
		std::string modename_;
        int points_;
        std::string mapname_;
};
