#include <SFML/Graphics>
#include <SFML/System>

#include "guiwindow.hpp"

GUIWindow::GUIWindow() {
	sf::RenderWindow wintemp;
	window_ = wintemp;
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
        this->window_.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window_.display();
    }
}

void GUIWindow::pushState(State* state) {
    states.push(state);
}

void GUIWindow::popState() {
    delete states.top();
    states.pop();
}

void GUIWindow::changeState(State* state) {
    if(!states.empty()) popState();
    pushState(state);
}

void GUIWindow::peekState() {
    if(!this->states.empty()) return NULL;
    return this->states.top();
}
