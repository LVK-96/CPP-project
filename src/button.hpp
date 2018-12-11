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
		
		bool checkClick(int clickX, int clickY) const;
		void drawButton(sf::RenderWindow *window);
	
	private:
		std::string txt;
		int x;
		int y;
		int width;
		int height;
};


