// ITP 365 Fall 2015
// HW4 - Wedding Planner
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#pragma once
#include "Vector.h"
#include "Hevent.h"

class hcal
{
private:
	Vector <hevent*> mVector;
	//Function: binarySearchPart
	//Purpose: Given a HEvent pointer, finds an holiday within the memeber vector of hcal. 
	//Input: Accepts an HEvent pointer, an interger to determine the start/end of the range the search looks through. 
	//Output: Index the value is at, or -1 if not found
	int binarySearchPart(hevent* hevent, int start, int end); 
public:
	//Default Constructor
	hcal();

	//Function: addEvent
	//Purpose:adds the inputted Hevent pointer to the end of HEvent pointer vector. 
	//Input: Hevent pointer
	//Output: Nothing
	void addEvent(hevent* hevent);

	//getters

	//Gets the size of the member vector. 
	int getVecSize();

	//Getter accesses the underlying vector, 
	//accepts an unsigned int, and returns pointer appropriate HEvent pointer
	hevent* getHevent(unsigned int index);

	//Function: int search
	//Purpose:Checks the HEvent (pointed by the parameter pointer)
	// against the other HEvents in the HCal to see if something is scheduled on this date
	//Input: Hevent pointer
	//Output: Index from the private binarySearchPart function
	int search(hevent* hevent);

};