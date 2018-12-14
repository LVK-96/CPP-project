#pragma once
#include <stack>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "state.hpp"
/*GUIWindow class allows for using a signle window throughout the program, it is passed as a reference to gamestate classes that draw stuff into it. 
  The different gamestates are stored in a stack.*/
  
class State; //forward declaration

class GUIWindow {
	public:
		GUIWindow();
		~GUIWindow();
		GUIWindow& operator= (const GUIWindow& g) = default;
		GUIWindow(const GUIWindow& g) = default;
	
		void pushState(State *state); //add new state to stack
		void popState(); //remove state from states
		void changeState(State *state); //change state on window
		State *peekState(); //returns the state on top of the stack
		void gameLoop(); //calls input handlers, draws window
		sf::RenderWindow& getWindow();//returns a reference to the window to be used elsewhere
	
	protected:
		std::stack<State*> states_;
		sf::RenderWindow window_;
};

