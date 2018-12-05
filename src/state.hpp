#pragma once
#include "guiwindow.hpp"

//virtual class for game states
class GUIWindow;//forward declaration

class State {
    public:
        virtual ~State(){};//virtual destructor
        virtual void draw(const float dt)=0;
        virtual void update(const float dt)=0;
        virtual void handleInput()=0;
	protected:
		GUIWindow *guiWindow_;

};
/*
virtual destructor is used to inform that when a derived classes destructor is called through a pointer to the base class,
the derived classes destructor will always be called
*/