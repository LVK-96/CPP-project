#include <stack>
#include <SFML/Graphics>

class State;

class GUIWindow {
    public:
        GUIWindow();
        ~GUIWindow();

        void pushState(State *state); //add new state to stack
        void popState(); //remove state from states
        void changeState(State *state); //change state on window
        State *peekState(); //returns the state on top of the stack
        void gameLoop(); //calls input handlers, draws window
	protected:
        std::stack<State*> states_;
        sf::RenderWindow window_;
};

/* In tilemaching.cpp/main: 
** GUIwindow guiWindow;
** guiWindow.pushState(new StartMenu(&guiWindow)); -> add start menu to the state stack
** gameLoop();
*/
