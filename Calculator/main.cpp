// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW2.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>

#include "gwindow.h"
#include "gevents.h"
#include "ginteractors.h"
#include "strlib.h"

#include "Numpad.h"
#include "Calculator.h"
#include "Keypad.h"
#include "PhoneSystem.h"

// Function: mainMenu
// Purpose: Displays the main menu for itpPhone
// Input: Window to draw the menu in
// Output: None
void mainMenu(GWindow& gw);

// Function: phoneApp
// Purpose: Runs the phone dialer app's behavior
void phoneApp();

// Function: calcApp
// Purpose: Runs the calculator app's behavior
void calcApp();

// Function: main
// Purpose: Entry point
int main(int argc, char** argv)
{
	// Create a 480x720 window
	GWindow gw(480, 720);
	gw.setWindowTitle("itpPhone");
	
	mainMenu(gw);
	
	return 0;
}

// Function: mainMenu
// Purpose: Displays the main menu for itpPhone
// Input: Window to draw the menu in
// Output: None
void mainMenu(GWindow& gw)
{
	GButton* calcButton = new GButton("CALCULATOR");
	calcButton->setActionCommand("calc");
	calcButton->setSize(150, 75);
	gw.add(calcButton, 165, 100);
	pause(5);
	
	GButton* phoneButton = new GButton("PHONE");
	phoneButton->setActionCommand("phone");
	phoneButton->setSize(150, 75);
	gw.add(phoneButton, 165, 200);
	pause(5);
	
	GEvent e = waitForEvent(ACTION_EVENT);
	GActionEvent ae(e);
	if (ae.getActionCommand() == "calc")
	{
		gw.close();
		calcApp();
	}
	else if (ae.getActionCommand() == "phone")
	{
		gw.close();
		phoneApp();
	}
	else
	{
		error("Unknown main menu action.");
	}
}

// Function: phoneApp
// Purpose: Runs the phone dialer app's behavior
void phoneApp()
{
	GWindow gw(480, 720);
	gw.setWindowTitle("itpPhone");
	
	Keypad keypad(gw);
	PhoneSystem phoneSystem;
	
	gw.drawLabel("PHONE", 240, 25);
	
	std::string key;
	while (true)
	{
		key = keypad.getKeyPress();
		if (key == "back")
		{
			phoneSystem.backspace();
		}
		else if (key == "quit")
		{
			exitGraphics();
		}
		else
		{
			phoneSystem.addDigit(key[0]);
		}
		
		gw.setColor("WHITE");
		gw.fillOval(0, 0, 480, 200);
		
		gw.setColor("BLACK");
		gw.drawLabel("PHONE", 240, 25);
		gw.drawLabel(phoneSystem.getNumber(), 240, 75);
		
		gw.drawLabel(phoneSystem.lookupNumber(), 240, 125);
	}
}

// Function: calcApp
// Purpose: Runs the calculator app's behavior
void calcApp()
{
	GWindow gw(480, 720);
	gw.setWindowTitle("itpPhone");
	
	Numpad numpad(gw);
	Calculator calc;
	
	gw.drawLabel("CALCULATOR", 240, 25);
	
	std::string key;
	std::string displayLabel;
	std::string currNum;
	while (true)
	{
		key = numpad.getKeyPress();
		if (stringIsInteger(key))
		{
			currNum += key;
			displayLabel = currNum;
		}
		else if (key == "enter" && stringIsInteger(currNum))
		{
			calc.pushNum(stringToInteger(currNum));
			displayLabel = currNum;
			currNum.clear();
		}
		else if (key == "quit")
		{
			exitGraphics();
		}
		else
		{
			// Push the current number on the stack
			if (stringIsInteger(currNum))
			{
				calc.pushNum(stringToInteger(currNum));
				currNum.clear();
			}
			
			CalcType type = ADD;
			if (key == "-")
			{
				type = SUB;
			}
			else if (key == "*")
			{
				type = MUL;
			}
			else if (key == "/")
			{
				type = DIV;
			}
			
			calc.doCalc(type);
			displayLabel = std::to_string(calc.peekTop());
		}
		
		gw.setColor("WHITE");
		gw.fillOval(0, 0, 480, 200);
		
		gw.setColor("BLACK");
		gw.drawLabel("CALCULATOR", 240, 25);
		gw.drawLabel(displayLabel, 240, 75);
	}
}
