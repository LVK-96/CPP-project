# include "StartMenuGUI.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <stdio.h>


StartMenuGUI::StartMenuGUI(StartMenu menu) : menu(menu) { loopUserInput(); }

void StartMenuGUI::printStartMenu() 
{
	system("CLS");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "|    press a to start game     |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|press b to configure settings |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|  press c to view highscores  |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|       press q to quit        |" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void StartMenuGUI::printSettingsMenu()
{
	system("CLS");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "|           SETTINGS           |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "                                " << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|  press c to view highscores  |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|       press q to quit        |" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}


void StartMenuGUI::loopSettingsMenu() 
{
	bool valid_command = false;
	char command;

	while (!valid_command) {
		printSettingsMenu();
		std::cin >> command;
		switch (command) {
		case 'a': valid_command = true;
			break;
		case 'b': valid_command = true;
			break;
		case 'c': printLeaderBoard();
			break;
		case 'd': valid_command = true;
			break;
		case 'q': valid_command = true;
			break;
		}
	}
}

void StartMenuGUI::printLeaderBoard() 
{
	//could use a different leaderboard depending on user input for example for a different map
	std::ifstream infile("highscores.txt");
	std::string line;
	


	char test;
	system("CLS");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "|          LeaderBoard         |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;

	std::getline(infile, line); //getline defined in the strings stream header

	std::cout << "| 1. " << line << std::endl;
	std::cout << "|------------------------------|" << std::endl;

	std::getline(infile, line);

	std::cout << "| 2. " << line << std::endl;
	std::cout << "|------------------------------|" << std::endl;

	std::getline(infile, line);

	std::cout << "| 3. " << line << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "                                " << std::endl;
	std::cout << "   Press any key to continue    " << std::endl;
	std::cin >> test;
}

int StartMenuGUI::printMapMenu(int howmany)
{
	//show five at a time
	//use a while loop and while EOF
	std::ifstream infile("maplist.txt");
	std::string line;

	int j = 0; //counter
	howmany = howmany * 5; //if howmany = 1, wwe dont read the first 5 lines 
	//take the extra away
	while (std::getline(infile, line) && j < howmany) {
		j = j + 1;
	}

	int i = 0;

	system("CLS");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "|          Choose Map          |" << std::endl;
	std::cout << "|------------------------------|" << std::endl;
	
	std::cout << "| " << i + 1 << ". " << line << std::endl; //the getline that has been taken before in the loop will be printed here
	i = i + 1;
	
	
	std::cout << "|------------------------------|" << std::endl;
	

	
	while (std::getline(infile, line) &&  i < 5) {
		std::cout << "| " << i + 1 << ". " << line << std::endl;
		std::cout << "|------------------------------|" << std::endl;
		i = i + 1;
		
	}
	line;
	std::getline(infile, line);
	line;
	//could check that if EOF too
	if (i == 5) {
		//if more maps might exist
		std::cout << "                                " << std::endl;
		std::cout << "   Press 6 for the next maps    " << std::endl;
	}
	else if (i < 5 && howmany != 0) {
		//to look at the first maps again
		std::cout << "                                " << std::endl;
		std::cout << "     Press 6 to start over      " << std::endl;
	}

	std::cout << "                                " << std::endl;
	std::cout << "       Press q to go back       " << std::endl;
	std::cout << "                                " << std::endl;
	return i;
}

void StartMenuGUI::loopMapMenu() 
{
	int i = 0;

	bool valid_command = false;
	char command;
	int choice_count = printMapMenu(i);//print the choices//return the max amount of choices that the person has

	while (!valid_command) {

		std::cin >> command;
		if (command == '1' && choice_count >= 1) {
			//choice is the choice_count*1 map on the maplist/file
			//need to parse input from the file and set it as the map file for StartMenu class and which then creates a game with this map file
			//Use an help function
			valid_command = true;
		}
		else if (command == '2' && choice_count >= 2) {
			valid_command = true;
		}
		else if (command == '3' && choice_count >= 3) {
			valid_command = true;
		}
		else if (command == '4' && choice_count >= 4) {
			valid_command = true;
		}
		else if (command == '5' && choice_count >= 5) {
			valid_command = true;
		}
		else if (command == '6' && choice_count >= 5) {
			//check the difference with the next one
			//show the rest of the maps if they exist
			i = i + 1;
			choice_count = printMapMenu(i);//print the choices//return the max amount of choices that the person has
			valid_command = false;//dont break out just yet
		}
		else if (command == '6' && choice_count < 5) {
			//no more maps exist
			//start over
			i = 0;
			choice_count = printMapMenu(i);
			valid_command = false;//dont break out just yet
		}
		else if (command == 'q' && choice_count >= 1) {
			valid_command = true;
		}
	}
}

void StartMenuGUI::loopUserInput()
{
	bool quit_game = false;
	char command;

	//print startmenu options

	while (!quit_game) {
		printStartMenu();
		std::cin >> command;
		switch (command) {
		case 'a': loopMapMenu();//start game
			break;
		case 'b': loopSettingsMenu();//configure settings
			break;
		case 'c': printLeaderBoard();//view highscore
			break;
		case 'd': break;
			break;
		case 'q': quit_game = true; //quit
			break;
		}
	}
}