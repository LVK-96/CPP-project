#include "guiwindow.hpp"
#include <cmath>
#include <iostream>
void GUIWindow::draw(matrix) const {
	/*std::vector<std::vector<int> > matrix(8, std::vector<int>(8,0));
	srand(time(NULL));

	//loops through the map and fills empty spaces with random tiles
	for (unsigned int j = 0; j < matrix.size(); j++) {
		for (unsigned int i = 0; i < matrix[j].size(); i++) {
			if (matrix[j][i] == 0) {
				matrix[j][i] = rand() % 4 + 1;
			}
		}
	}*/

	
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(48.f, 8);
	shape.setFillColor(sf::Color::Green);
	
    const int distance = 100; //distance between dots
    const float height = std::sqrt(std::pow(distance,2.f));
	unsigned int clickX;
	unsigned int clickY;

     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		/*shape.setPosition(10.f, 50.f);
        window.draw(shape);
		*/
		for (unsigned int j=0; j < matrix.size(); j++){
        	for (unsigned int i = 0; i < matrix[j].size(); i++) {
	            if (j%2==0) shape.setPosition(j*distance, i*height); //even rows
		        else shape.setPosition(j*distance, i*height); //odd rows
				if (matrix[j][i] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[j][i] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[j][i] == 3) shape.setFillColor(sf::Color::Red);
				else shape.setFillColor(sf::Color::Green);
				if (j == clickX && i == clickY) shape.setFillColor(sf::Color::Magenta);
                window.draw(shape);
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
    		if (event.mouseButton.button == sf::Mouse::Left)
    		{
				clickX = event.mouseButton.x / 100;
				clickY = event.mouseButton.y / 100;
        		std::cout << "the left button was pressed" << std::endl;
        		std::cout << "mouse x: " << clickX << std::endl;
        		std::cout << "mouse y: " << clickY << std::endl;
				
    		}
		}

		
        window.display();
    }
}
