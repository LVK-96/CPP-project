#include <SFML/Graphics>

class GameGUI : public State {
    public:
        GameGUI(GUIWindow *guiWindow, Game *game);

        virtual void draw(const float dt); 
        virtual void update(const float dt);
        virtual void handleInput(); // window event loop, handle game inputs
	private:
		GUIWindow *guiWindow_;
		Game *game_;
};
