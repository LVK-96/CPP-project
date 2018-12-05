#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "guiwindow.hpp"

GUIWindow::GUIWindow() {
    window_.create(sf::VideoMode(800,600), "Match 3");
    window_.setFrameRateLimit(60);
}

GUIWindow::~GUIWindow() {
    while(!states.empty()) popState();
}

void GUIWindow::gameLoop() {
    sf::Clock clock;

    while (window_.isOpen()) {
        sf::Time elapsed=clock.restart();
        float dt=elapsed.asSeconds();

        if (peekState()==NULL) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        window_.clear(sf::Color::Black);
        peekState()->draw(dt);
        window_.display();
    }
}

void GUIWindow::pushState(State* state) {
    states.push(state);
}

void GUIWindow::popState() {
    delete states_.top();
    //pop method calls the destructor of the item that is popped, move memory deallocation to the destructor of the state
    states.pop();
}

void GUIWindow::changeState(State* state) {
    //why is this method needed
    if(!states.empty()) popState();
    pushState(state);
}

void GUIWindow::peekState() {
    if(!states.empty()) return NULL;
    return states.top();
}
