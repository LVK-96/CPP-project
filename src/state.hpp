#include "guiwindow.hpp"

//virtual class for game states

class State {
    public:
        virtual void draw(const float dt)=0;
        virtual void update(const float dt)=0;
        virtual void handleInput()=0;
	protected:
		GUIWindow *guiWindow;

};
