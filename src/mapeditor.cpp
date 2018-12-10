#include "mapeditor.hpp"

MapEditor::MapEditor(GUIWindow guiWindow): guiWindow_(guiWindow) {
	Map map(std::vector<std::vector<int>> temp(8, std::vector<int>(8,0)));	
	MapEditor::setSize();
}

void MapEditor::setSize() {
	sf::Text text;
	text.setFont(font);
	text.setString("Choose map size:\n"
					"a 8x8 \n\n"
					"b 16x16 \n\n"
					"c 32x32 \n\n"
					"press q to go back");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);
}

