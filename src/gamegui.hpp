#pragma once
#include <SFML/Graphics.hpp>
#include "startmenu.hpp"
//forward declarations for GUIWindow and Game. Compiler needs this for memory allocation
class GUIWindow;
class Game;

class GameGUI : public State {
    public:
        GameGUI(GUIWindow *guiWindow, Game *game);
        ~GameGUI();

        virtual void draw(const float dt); 
        virtual void update(const float dt);
        virtual void handleInput(); // window event loop, handle game inputs
	private:
		GUIWindow *guiWindow_;
		Game *game_;
};
