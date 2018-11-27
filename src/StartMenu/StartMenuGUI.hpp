#ifndef STARTMENUGUI_HEADER
#define STARTMENUGUI_HEADER

# include <string>
# include "StartMenu.hpp"


class StartMenuGUI 
{
public:
	StartMenuGUI(StartMenu menu);//default constructor
    void loopUserInput();
	void printStartMenu();

	void loopSettingsMenu();
	void printSettingsMenu();

	void printLeaderBoard();

	int printMapMenu(int howmany);
	void loopMapMenu();//returns the maps files name

private:
	StartMenu menu;
};

#endif // !STARTMENUGUI_HEADER