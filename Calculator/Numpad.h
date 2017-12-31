// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW2.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//  Numpad.h
//  Defines Numpad class, which is used to display calculator buttons.
//

#pragma once

#include "gwindow.h"

// Numpad class for UI presentation of calculator buttons
class Numpad
{
public:
	// Function: Constructor
	// Purpose: Creates a numpad of buttons in a window
	// Input: Window to create the buttons
	// Output: None
	Numpad(GWindow& window);
	
	// Function: getKeyPress
	// Purpose: Returns the string name of any button pressed.
	//          Does not return until a button press occurs.
	// Input: None
	// Output: String name of button pressed
	std::string getKeyPress();
	
	// Function: Destructor
	// Purpose: Does nothing
	~Numpad();
private:
	// Function: addButton
	// Purpose: Helper function used by constructor to create buttons
	void addButton(const std::string& name, const std::string& action,
				   double x, double y, double width, double height);
	
	// GWindow that the buttons reside in
	GWindow& mWindow;
};
