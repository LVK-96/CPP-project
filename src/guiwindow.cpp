#include "guiwindow.hpp"

void GUIWindow::draw(std::vector<std::vector<int> > matrix) const {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(48.f, 8);
	shape.setFillColor(sf::Color::Transparent);
	
    const int distance = 100; //distance between objects
    const float height = std::sqrt(std::pow(distance,2.f));
        //sf::Event event;

        window.clear();
		for (unsigned int i=0; i < matrix.size(); i++){
        	for (unsigned int j = 0; j < matrix[i].size(); j++) {
	            shape.setPosition(j*distance, i*height);
				if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
				else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
				else shape.setFillColor(sf::Color::Magenta);
                window.draw(shape);
			}
		}

		
        window.display();
}

std::vector<unsigned int> GUIWindow::getInput(std::vector<std::vector<int> > matrix) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(48.f, 8);
	shape.setFillColor(sf::Color::Green);
	

	std::vector<unsigned int> newCoords (4, 10000); //4 zeros in a vector
	
    const int distance = 100; //distance between dots
    const float height = std::sqrt(std::pow(distance,2.f));
	

     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*window.clear();
		shape.setPosition(0*distance, 0*height);
        window.draw(shape);*/
		
		for (unsigned int i=0; i < matrix.size(); i++){
        	for (unsigned int j = 0; j < matrix[i].size(); j++) {
	            shape.setPosition(j*distance, i*height);
				if (matrix[i][j] == 1) shape.setFillColor(sf::Color::Yellow);
				else if (matrix[i][j] == 2) shape.setFillColor(sf::Color::Blue);
				else if (matrix[i][j] == 3) shape.setFillColor(sf::Color::Red);
				else if (matrix[i][j] == 4) shape.setFillColor(sf::Color::Green);
				else shape.setFillColor(sf::Color::Transparent);
                window.draw(shape);
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
    		if (event.mouseButton.button == sf::Mouse::Left)
    		{
				unsigned int clickX = (event.mouseButton.x / 100);
				unsigned int clickY = (event.mouseButton.y / 100);
				if (newCoords[2] != clickX || newCoords[3] != clickY) {
					newCoords[0] = newCoords[2];
					newCoords[1] = newCoords[3];
					newCoords[2] = clickX;
					newCoords[3] = clickY;
		    		std::cout << "the left button was pressed" << std::endl;
		    		std::cout << "mouse x: " << newCoords[2] << std::endl;
		    		std::cout << "mouse y: " << newCoords[3] << std::endl;
				}
    		}
		}
		if (newCoords[0] < 10000 && newCoords[1] < 10000) {
			return newCoords;
		}

		
        window.display();
    }
	return newCoords;
}
