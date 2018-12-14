#include "button.hpp"


Button::Button(std::string t, int xcord, int ycord, int w, int h){
	txt = t;
	x = xcord;
	y = ycord;
	width = w;
	height = h;
}

bool Button::checkClick(int clickX, int clickY) const {
	if (clickX > x && clickX < (x+width) && clickY > y && clickY < (y+height))
		return true;
	return false;
}

void Button::drawButton(sf::RenderWindow& window) {
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(x, y);
	rectangle.setFillColor(sf::Color(47,79,79));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color::White);

	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	sf::Text text;
	text.setFont(font);

	text.setString(txt);
	text.setCharacterSize(20);
	text.setColor(sf::Color::White);
	text.setPosition(x + (width/2) - (text.getGlobalBounds().width / 2), y + (height/2) -(text.getGlobalBounds().height / 2));
	

	window.draw(rectangle);
	window.draw(text);

}
