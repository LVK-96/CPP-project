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
        if (peekState()==NULL) {continue;}
        if(peekState()->handleInput()) {popState();}//remove a state from the stack
		
		while(peekState()->update()){}
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
    
    //pop method calls the destructor of the item that is popped, memory deallocation moved to the destructor - does it??
    //check if this works as expected
}

void GUIWindow::changeState(State* state) {
    State *temp = states_.top();
    states_.pop();
    pushState(state);
	pushState(temp);
}

State *GUIWindow::peekState() {
    if(states_.empty()) {return NULL;}
    return states_.top();
}

//returns a reference to the window so that it can be used outside of this class
sf::RenderWindow& GUIWindow::getWindow(){
    return window_;
}
