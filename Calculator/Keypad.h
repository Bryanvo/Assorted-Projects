// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW2.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//  Keypad.h
//  Defines Keypad class, which is used to display dialer buttons.
//

#pragma once
#include "gwindow.h"

class Keypad
{
public:
	// Function: Constructor
	// Purpose: Creates a keypad of buttons in a window
	// Input: Window to create the buttons
	// Output: None
	Keypad(GWindow& window);
	
	// Function: getKeyPress
	// Purpose: Returns the string name of any button pressed.
	//          Does not return until a button press occurs.
	// Input: None
	// Output: String name of button pressed
	std::string getKeyPress();
	
	// Function: Destructor
	// Purpose: Does nothing
	~Keypad();
private:
	// Function: addButton
	// Purpose: Helper function used by constructor to create buttons
	void addButton(const std::string& name, const std::string& action,
				   double x, double y, double width, double height);
	
	// GWindow that the buttons reside in
	GWindow& mWindow;
};
