// ITP 365 Spring 2016
// HW2 – itpPhone
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: windows
//
// PhoneSystem.cpp
// Implements PhoneSystem class
//

#include "PhoneSystem.h"
#include <fstream>
#include <set.h>

// Function: Constructor
// Purpose: Constructs two maps --
//          (1) area codes -> locations
//              (loaded from areacodes.txt)
//          (2) phone numbers -> contacts
//              (loaded from contacts.txt)
// Input: None
// Output: None
PhoneSystem::PhoneSystem()
{
	// TODO: Implement
	std::string area; 
	std::ifstream fileA("areacodes.txt");
	if (fileA.is_open())//Reads in the area code text. 
	{
		while (!fileA.eof())
		{
			std::getline(fileA, area);
			std::string key = area.substr(0, 3);//Stores in the name of the area code to string. 
			std::string value = area.substr(4);
			areaCode[key] = value;
		}

	}
	else
	{
		error("Failed to load in file");
	}

	std::string first;
	std::ifstream fileB("contacts.txt");
	if (fileB.is_open())//Reads in the contacts text
	{
		while (!fileB.eof())
		{
			std::getline(fileB, first);
			std::string key = first.substr(0, 3) + first.substr(4, 3) + first.substr(8, 4);//Stores the number without hyphens. 
			std::string value = first.substr(13);
			phoneNum[key] = value; 
		}
	}
	else
	{
		error("Failed to load in file");
	}
}

// Function: addDigit
// Purpose: Called when the user adds a digit
//          to the current phone number
// Input: Digit to add (to the end of the number)
// Output: None
void PhoneSystem::addDigit(char digit)
{
	// TODO: Implement
	currPhone += digit;//Member string concatenates a number.

}

// Function: backspace
// Purpose: Removes the rightmost digit from the number
// Input: None
// Output: None
void PhoneSystem::backspace()
{
	// TODO: Implement
	currPhone.pop_back();//Deletes an element on the stack to delete last inputed number. 
}

// Function: getNumber
// Purpose: Returns the current number the user has dialed
// Input: None
// Output: Current number user has dialed
std::string PhoneSystem::getNumber()
{
	// TODO: Implement
	return currPhone; // FIX TO RETURN CORRECT VALUE
}

// Function: lookupNumber
// Purpose: Looks up the current number in the two maps:
//          (1) First checks if this number is a contact
//          (2) Otherwise, checks if the first three digits
//              are a known area code
// Input: None
// Output: Returns a string that contains either:
//         (a) The name of the contact
//         (b) The location of the area code
//         (c) "UNKNOWN" if it's neither a contact nor
//             contains a valid area code
std::string PhoneSystem::lookupNumber()
{
	// TODO: Implement
	std::string Retcontact;
	if (phoneNum.containsKey(currPhone))//If the number is a contained in the contact map, this returns the name of the contact. 
	{
		Retcontact = phoneNum.get(currPhone);
	}
	else if (areaCode.containsKey(currPhone))//If the area code is contained in the areaCode map, this returns the area. 
	{
		Retcontact = areaCode.get(currPhone);
	}
	else//If the number is unknown, this returns unknown. 
	{
		return "Unknown";
	}
	return Retcontact; //Returns contact name. 
}
