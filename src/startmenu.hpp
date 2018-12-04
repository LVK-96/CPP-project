#include <SFML/Graphics.hpp>

#include "state.hpp"

class StartMenu : public State {
    public:
        StartMenu(GUIWindow *guiWindow);

        virtual void draw(const float dt); //changes the view that will be drawn to window (defined in guiwindow class)
        virtual void update(const float dt);
        virtual void handleInput(); // window event loop, close window or call startGame

        void startGame(); // add game to the state stack

    private:
		GUIWindow *guiWindow_;
};
