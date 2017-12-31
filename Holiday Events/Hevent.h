// ITP 365 Fall 2015
// HW4 - Wedding Planner
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#pragma once
#include <string>
#include <ostream>
#include "dateconv.h"

class hevent 
{
	//Private member variables
private:
	unsigned long long mTime; 
	std::string mName;
	std::string mType; 
	//Public functions 
public:
	//Parameterized Constructor
	hevent(unsigned long long time, std::string name, std::string type);

	//getter for member variable mTime
	unsigned long long getTime();

	//getter for member variable mType;
	std::string getName();

	//getter for member variable mType;
	std::string getType();

	//Logical operators

	//Overloads operator >
	friend bool operator>(hevent& left, hevent& right);

	//Overloads operator <
	friend bool operator<(hevent& left, hevent& right);

	//Overloads operator ==
	friend bool operator==(hevent& left, hevent& right);

	//Overloads operator <<
	friend std::ostream& operator<<(std::ostream& os, hevent& obj);

};
