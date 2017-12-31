// ITP 365 Fall 2015
// HW4 - Wedding Planner
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#include "Hevent.h"


//Parameterized Constructor
hevent::hevent(unsigned long long time, std::string name, std::string type)
{
	mTime = time;
	mName = name;
	mType = type;
}

//Getter for mTime
unsigned long long hevent::getTime()
{
	return mTime;
}

//Getter for mName
std::string hevent::getName()
{
	return mName;
}

//Getter for mType
std::string hevent::getType()
{
	return mType;
}

//Overloads operator >
bool operator>(hevent& left, hevent & right)
{
	//Conditionals that compare which event object is greater
	if (left.mTime > right.mTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloads operator <
bool operator<(hevent & left, hevent & right)
{
	//Conditionals that compare which event object is less
	if (left.mTime < right.mTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloads operator ==
bool operator==(hevent & left, hevent & right)
{
	//Conditionals to determine if hevent objects are equivalent
	if (left.mTime == right.mTime) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloads operator <<
std::ostream & operator<<(std::ostream & os, hevent& obj)
{
	//Couts the member variables through Getters
	os << getMonth(obj.mTime) << "/" << getMonthDay(obj.mTime) << "/" << getYear(obj.mTime) << " is " 
		<< obj.mName << " (" << obj.mType << ") "<< std::endl;
	//Returns os stream
	return os;
}
