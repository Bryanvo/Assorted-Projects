// ITP 365 Fall 2015
// HW4 - Wedding Planner
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#include "Hcal.h"



int hcal::binarySearchPart(hevent* hevent, int start, int end)
{
	//Case if event is not found.
	if (end < start)
	{
		return -1;
	}

	int middleIndex = (end + start) / 2;

	if (*(mVector[middleIndex]) == *(hevent))
	{
		return middleIndex;
	}
	//Binary search the first half
	if (*(mVector[middleIndex]) > *(hevent))
	{
		return binarySearchPart(hevent, start, middleIndex - 1);
	}
	//Binary search the second half
	else
	{
		return binarySearchPart(hevent, middleIndex + 1, end);
	}
}

//Default Constructor
hcal::hcal()
{
}

//Add event function
void hcal::addEvent(hevent * hevent)
{
		mVector.add(hevent);
}

//getter for size of private member vector
int hcal::getVecSize()
{
	return mVector.size();
}

//getter for dynamically alocated vector
hevent *hcal::getHevent(unsigned int index)
{
	return mVector[index];
}

//search function
int hcal::search(hevent * hevent)
{
	return binarySearchPart(hevent, 0,  mVector.size()- 1);
}



