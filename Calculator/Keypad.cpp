// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW2.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//  Keypad.cpp
//  Implements Keypad class
//

#include "Keypad.h"
#include "gevents.h"
#include "ginteractors.h"
#include <string>

// Function: Constructor
// Purpose: Creates a keypad of buttons in a window
// Input: Window to create the buttons
// Output: None
Keypad::Keypad(GWindow& window)
: mWindow(window)
{
	const double START_X = 127.5;
	const double START_Y = 210.0;
	const double WIDTH = 75.0;
	const double HEIGHT = 75.0;
	
	double x = START_X;
	double y = START_Y;
	
	// 1 through 9
	for (int digit = 1; digit < 10; digit++)
	{
		std::string digitStr = std::to_string(digit);
		addButton(digitStr, digitStr, x, y, WIDTH, HEIGHT);
		x += WIDTH;
		if (x >= (START_X + WIDTH * 3))
		{
			x = START_X;
			y += HEIGHT;
		}
	}
	
	// 0 and backspace
	x += WIDTH;
	addButton("0", "0", x, y, WIDTH, HEIGHT);
	x += WIDTH;
	addButton("<--", "back", x, y, WIDTH, HEIGHT);
	
	// QUIT
	addButton("QUIT", "quit", 165, 600, 150, 75);
}

// Function: getKeyPress
// Purpose: Returns the string name of any button pressed.
//          Does not return until a button press occurs.
// Input: None
// Output: String name of button pressed
std::string Keypad::getKeyPress()
{
	pause(5);
	GEvent e = waitForEvent(ACTION_EVENT);
	GActionEvent ae(e);
	return ae.getActionCommand();
}

// Function: addButton
// Purpose: Helper function used by constructor to create buttons
void Keypad::addButton(const std::string& name, const std::string& action,
					   double x, double y, double width, double height)
{
	GButton* button = new GButton(name);
	button->setActionCommand(action);
	button->setSize(width, height);
	mWindow.add(button, x, y);
	pause(5);
}

// Function: Destructor
// Purpose: Does nothing
Keypad::~Keypad()
{
	
}
