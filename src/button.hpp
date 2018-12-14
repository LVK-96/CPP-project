#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "guiwindow.hpp"

class Button {
	public:
		Button() = default;
		Button(std::string t, int xCord, int ycord, int w, int h);
		~Button() = default;
		
		bool checkClick(int clickX, int clickY) const; //return true if click was inside the button
		void drawButton(sf::RenderWindow& window); //draws the button the the parameter window
	
	private:
		std::string txt;
		int x;
		int y;
		int width;
		int height;
};


