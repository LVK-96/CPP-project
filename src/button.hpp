#pragma once
#include <string>


class Button {
	public:
		Button(std::string text, int x, int y, int w, int h);
		~Button() = default;
		
		bool checkClick(int clickX, int clickY) const;
		void drawButton(sf::RenderWindow window);
	
	private:
		std::string text;
		int x;
		int y;
		int width;
		int height;
};

GameGUI::GameGUI(GUIWindow& guiWindow, std::string mapname): guiWindow_(guiWindow)

Button::Button(std::string t, int xcord, int ycord, int w, int, h) : text(t), x(xcord), y(ycord), width(w), height(h) {}

bool Button::checkClick(int clickX, int clickY) const {
	if (clickX > x && clickX < (x+width) && clickY > y && clickY < (y+height))
		return true;
	return false;
}

void Button::drawButton(clickX > x && clickX < (x+width) {

}
