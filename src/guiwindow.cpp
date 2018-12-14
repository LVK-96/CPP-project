#include "guiwindow.hpp"


GUIWindow::GUIWindow() {
    window_.create(sf::VideoMode(800,850), "Match 3");
    window_.setFramerateLimit(60);
}

GUIWindow::~GUIWindow() {
    while(!states_.empty()) {popState();}
}

void GUIWindow::gameLoop() {

    while (window_.isOpen()) {
        if (peekState()==NULL) {continue;} //empty stack
        if(peekState()->handleInput()) {popState();}//remove a state from the stack
		
		while(peekState()->update()){} //necessary for GameGUI udpate to work  
        window_.clear(sf::Color::Black);
        peekState()->draw();
        window_.display();
    }
}

void GUIWindow::pushState(State* state) {
    states_.push(state);
}

void GUIWindow::popState() {
    State *temp = states_.top();
    states_.pop();
    delete temp;
    //pop method calls the destructor of the item that is popped
}

void GUIWindow::changeState(State* state) {
    State *temp = states_.top();
    states_.pop();
    pushState(state);
	pushState(temp);
	/*Top state is pushed back into stack. This avoids returning into a deleted object, in the changeState function*/
}

State *GUIWindow::peekState() {
    if(states_.empty()) {return NULL;}
    return states_.top();
}

sf::RenderWindow& GUIWindow::getWindow() {
    return window_;
}
