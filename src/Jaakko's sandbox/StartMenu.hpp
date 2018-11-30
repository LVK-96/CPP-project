#ifndef STARTMENU_HEADER
#define STARTMENU_HEADER

//#include "StartMenuGUI.hpp"
# include <string>

class StartMenu 
{
public:
	StartMenu();//default constructor
    //void loopStartMenuAction();// useless --> all the user inpu looping can and will be done in the GUI

private:
	std::string username;
	std::string nextMapFileName;
};

#endif // !STARTMENU_HEADER