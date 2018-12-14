#pragma once
#include "guiwindow.hpp"
/*Pure virtual class that game states inherit. Allows running the game loop in GUIWindow*/

class GUIWindow;

class State {
    public:
        virtual ~State() = default;
        virtual void draw() = 0;
        virtual bool update(){return false;}
        virtual bool handleInput() = 0; //bool return value to determine whether to call the destructor of the state or not
	protected:
		GUIWindow *guiWindow_;

};
