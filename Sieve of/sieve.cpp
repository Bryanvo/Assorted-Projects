//ITP 365 Spring 2016
//HW1 - Sieve of Eratosthenes
//Name: Bryan VO
//Email: bryanvo@usc.edu
//Platform: Windows

#include "sieve.h"


void drawSquare(GWindow& square, int number, NumberType num, double x, double y)
{
	//Double variables to shift the printed number to the center of each square on grid. 
	double Xposition = x + 25.0;
	double Yposition = y + 25.0;
	//A switich that changes the color of the squares on the grid based on the numbertype.
	switch (num)
	{
	//Case for Unknown numbers
	case UNKNOWN:
		//Code prints a colored square on Gwindow. 
		square.setColor("white"); 
		square.fillRect(x, y, 50, 50);
		square.setColor("black");
		square.drawRect(x, y, 50, 50);
		break;
	//Case for Prime Numbers
	case PRIME:
		square.setColor("green");
		square.fillRect(x, y, 50, 50);
		square.setColor("black");
		square.drawRect(x, y, 50, 50);
		break;
	//Case for Composite Numbers
	case COMPOSITE:
		square.setColor("red");
		square.fillRect(x, y, 50, 50);
		square.setColor("black");
		square.drawRect(x, y, 50, 50);
		break;
	}
	square.setColor("black");
	//Converts vector of numbers to strings to outputed on the grid. 
		std::string convert;
		convert = integerToString(number);
		square.drawLabel(convert, Xposition, Yposition);
	

}

//Initvector function that adds elements to NumberType vector and int vector. 
void initVectors(Vector <int>& prime, Vector <NumberType>& type)
{
	NumberType element = UNKNOWN;

	for (int i = 2; i < 102; i++)
	{
		prime.add(i);
		type.add(element);
	}

}

//drawGrid function draws grid. 
void drawGrid(GWindow& grid, Vector <int>& sieve, Vector <NumberType>& type)
{
	double Xcounter = 0.0;
	double Ycounter = 0.0;
	for (int i = 0; i < sieve.size(); i++)
	{
		drawSquare(grid, sieve[i], type[i], Xcounter, Ycounter);
		//If statement changes to a new row if x is greater than 450. 
		if (Xcounter < 450.0) 
		{
			Xcounter += 50.0;
		}
		//If x is greater than 450, x is set to 0, and y is incremented by 50. 
		else if (Xcounter >= 450.0)
		{
			Xcounter = 0.0; 
			Ycounter += 50.0;
		}
	}
}

//calcNextPrime function. 
int calcNextPrime(Vector <int>& sieve, Vector <NumberType>& type, int startAt)
{
	int startIndex = startAt - 2; //Because the two vectos have indicies that are shifted by two, this int confinscates for the shift.
	type[startIndex] = PRIME;//startAt int is always prime
	for (int i = startIndex + 1; i < sieve.size(); i++)//Multiples the prime number and sets the result to composite. 
	{
		if (sieve[i] % startAt == 0)//Checks the mutliples of the prime number. 
		{
			type[i] = COMPOSITE;
		}
	}
	for (int i = startIndex + 1; i < sieve.size(); i++)//Finds the next unknown number and returns the number.
	{
		if (type[i] == UNKNOWN)
		{
			return sieve[i];
		}
	}
	return -1;//Ends function if there is no more unknown numbers.
}
