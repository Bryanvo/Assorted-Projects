//ITP 365 Spring 2016
//HW1 - Sieve of Eratosthenes
//Name: Bryan VO
//Email: bryanvo@usc.edu
//Platform: Windows

#include <iostream>
#include <string>
#include "vector.h"
#include "gwindow.h"
#include "strlib.h"

enum NumberType
{
	UNKNOWN, PRIME, COMPOSITE
};

// Function: calcNextPrime
// Purpose: Finds the next prime number and marks its multiples as composite.
// Input: A Vector of ints by reference, Vector of NumberTypes by reference, An int to start the for loop to test. 
// Output: Returns the prime number startAt, or -1 if there is no more unknown numbertypes.
int calcNextPrime(Vector <int>& sieve, Vector <NumberType>& type, int startAt);

// Function:initVector
// Purpose: Adds elements to the two vectors. The vector prime vector takes in the numbers on the grid,
// numbertype takes in the type of each number. 
// Input: A vector of ints by reference, and a vector of NumberTypes by reference. 
// Output: Returns Nothing
void initVectors(Vector <int>& prime, Vector <NumberType>& type);

// Function: drawSquare
// Purpose: Draws a single 50x50 square. 
// Input: A GWindow by reference, an int by value, a NumberType by value, a double x, and a double y.
// Output: Returns nothing.
void drawSquare(GWindow& square, int number, NumberType num, double x, double y);

// Function: drawGrid
// Purpose: Draws a a grid using drawSquare function. 
// Input: A GWindow by reference, a vector of ints by reference, a vector of NumberTypes by reference. 
// Output: Returns nothing.
void drawGrid(GWindow& grid, Vector <int>& sieve, Vector <NumberType>& type);