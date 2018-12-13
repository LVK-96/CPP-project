#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h> 
#include <utility> 

#include "state.hpp"
#include "gamegui.hpp"
#include "guiwindow.hpp"
#include "button.hpp"

class ScoreGUI: public State {
    public:
        ScoreGUI(GUIWindow& guiWindow);
        ~ScoreGUI() = default;

        virtual void draw();
        virtual bool handleInput(); // window event loop, close window or call startGame
		void loadScores();
		void deleteScores();
		std::string getStr();
    private:
		GUIWindow& guiWindow_;
		std::vector<std::pair<int, std::string>> scores;
		Button *backbutton_;
		Button *deletebutton_;
};
