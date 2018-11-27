# include "StartMenu.hpp"
//# include "StartMenuGUI.hpp"
# include "stdio.h"

#include <iostream>

StartMenu::StartMenu() : username("guest"), nextMapFileName("default")
{
	std::cout << "------------------------------" << std::endl;
	std::cout << "|       input username       |" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cin >> username;
	system("CLS");//clear console
}

/*void StartMenu::loopStartMenuAction()
{
	char quit_game = false;
    char userinput;
    while(!quit_game){
        userinput = menugui.loopUserInput();
        switch(userinput){
            case 'a': //start game//go to map selection
				break;
			case 'b': menugui.loopSettingsMenu();//settings
				break;
			case 'c': menugui.printLeaderBoard();//print the leaderboard
				break;
            case 'd': //do something
				break;
            case 'q': quit_game = true; 
				break;
        }
    }
}
*/