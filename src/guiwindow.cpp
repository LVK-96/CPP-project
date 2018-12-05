#include <SFML/System.hpp>

#include "guiwindow.hpp"
#include <iostream>

GUIWindow::GUIWindow() {
    window_.create(sf::VideoMode(800,600), "Match 3");
    window_.setFramerateLimit(60);
}

GUIWindow::~GUIWindow() {
    while(!states_.empty()) popState();
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
    states_.push(state);
}

void GUIWindow::popState() {
    states_.pop();//pop method calls the destructor of the item that is popped, memory deallocation moved to the destructor
}

void GUIWindow::changeState(State* state) {
    //why is this method needed
    if(!states_.empty()) popState();
    pushState(state);
}

State *GUIWindow::peekState() {
    if(states_.empty()) return NULL;
    return states_.top();
}

//returns a reference to the window so that it can be used outside of this class
sf::RenderWindow &GUIWindow::getWindow(){
    return this->window_;
}