#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "state.hpp"

class EndGame: public State {
    public:
        EndGame(int points, std::string mapname, std::string modename, GUIWindow& guiwindow);
        ~EndGame() = default;
		
		EndGame& operator= (const EndGame& e) = default;
		EndGame(const EndGame& e) = default;
		
        virtual void draw(); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual bool handleInput(); // window event loop, close window or call startGame


        void startGame(); // add game to the state stack
		void saveScore(std::string playername);
    private:
		int points_;
        std::string mapname_;
		std::string modename_;
		GUIWindow& guiWindow_;
		sf::Text filepath_;
};
