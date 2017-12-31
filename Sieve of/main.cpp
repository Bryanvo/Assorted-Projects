// ITP 365 Spring 2016
// HW1 - Sieve of Eratosthenes
// Name: Bryan Vo
// Email: bryanvo@usc.edu.edu
// Platform: Windows


#include "sieve.h"


int main(int argc, char** argv)
{
	// Create a 500x500 window
	GWindow gw(500, 500);
	
	//Intialize Vectors
	Vector<int> prime;
	Vector<NumberType> type;
	
	// TODO: Implement stuff
	initVectors(prime, type);
	

	int nextStart = 2;//Interger that the for loop in calcNextPrime starts at.
	//While loop that keeps looping calcNextPrime until it returns -1. 
	while (nextStart != -1)
	{
		nextStart = calcNextPrime(prime, type, nextStart);//Sets the next prime number to multiply. 
		drawGrid(gw, prime, type);//Draws the new edited grid. 
		
	}

	
	
	return 0;
}
