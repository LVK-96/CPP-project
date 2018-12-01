#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	std::cout << "Error" << std::endl;
	}
	sf::Text text;
	text.setFont(font);
	text.setString("press a to start game \n\n"
					"press b to configure settings \n\n"
					"press c to view highscores\n\n"
					"press q to quit");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	float xPos = 50;
	text.setPosition(xPos, 100);


	
    // run the program as long as the window is open
    while (window.isOpen())
    {
		sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Q)
                window.close();
			if (event.type == sf::Event::KeyPressed)
			{
	    		if (event.key.code == sf::Keyboard::Return)
	    		{
					std::cout <<"enter pressed" << std::endl;
	    		}
			}
        }

        // clear the window with black color
		window.clear();
		window.draw(text);

        window.display();
    }

    return 0;
}
