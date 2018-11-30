#include <SFML/Graphics>

#include "state.hpp"

class GameGUI : public State {
    public:
        GameGUI(GUIWindow *guiWindow);

        virtual void draw(const float dt); 
        virtual void update(const float dt);
        virtual void handleInput(); // window event loop, handle game inputs
    private:
        sf::View view_;
};
