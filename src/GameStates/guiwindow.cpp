#include <SFML/Graphics>
#include <SFML/System>

#include "guiwindow.hpp"

GUIWindow::GUIWindow() {
    this->window_.create(sf::VideoMode(800,600), "Match 3");
    this->window_.setFrameRateLimit(60);
}

GUIWindow::~GUIWindow() {
    while(!this->states.empty()) popState();
}

void GUIWindow::gameLoop() {
    sf::Clock clock;

    while (this->window_.isOpen()) {
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
    this->states.push(state);
}

void GUIWindow::popState() {
    delete this->states.top();
    this->states.pop();
}

void GUIWindow::changeState(State* state) {
    if(!this->states.empty()) popState();
    pushState(state);
}

void GUIWindow::peekState() {
    if(!this->states.empty()) return NULL;
    return this->states.top();
}