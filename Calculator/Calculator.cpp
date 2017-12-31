// ITP 365 Spring 2016
// HW2 – itpPhone
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: windows
//
// Calculator.cpp
// Implements Calculator class
//

#include "Calculator.h"

// Function: Constructor
// Purpose: Does nothing
Calculator::Calculator()
{
	
}

// Function: pushNum
// Purpose: Pushes number onto the stack
// Input: number to push
// Output: None
void Calculator::pushNum(int number)
{
	// TODO: Implement
	numbers.push(number);//Stack that takes in the number provided in the parameter. 
}

// Function: peekTop
// Purpose: Returns the number on top of the stack
//          (provided the stack is not empty)
// Input: None
// Output: Number on top of the stack
int Calculator::peekTop()
{
	// TODO: Implement
	int retVal = 0;
	if (!numbers.isEmpty())//Conditional to test if stack is not empty. 
	{
		retVal = numbers.peek();//Takes the value from the top 
								//of numbers stack and stores it into retval.
	}
	
	return retVal; // FIX TO RETURN CORRECT VALUE
}

// Function: doCalc
// Purpose: Performs the requested arithmetic,
//          provided there are two numbers on the stack.
//          Then pushes the result onto the stack.
//          Silently fails if the stack has less than two
//          numbers on it.
// Input: Type of arithmetic to perform
// Output: None
void Calculator::doCalc(CalcType type)
{
	int left = 0;
	int right = 0;
	int result; 
	// TODO: Implement
	if (numbers.size() >= 2)//Conditional to test if the size of the stack is greater than two. 
	{
		right = numbers.pop();//Takes the first number off the stack and stores it to interger right. 
		left = numbers.pop();//Takes the second number off the stack and stores it to interger left. 
	}
	//Switch statement selects the user's choice of operand. 
	switch (type)
	{
	case 0://Case for add.
		result = left + right;
		break;
	case 1://Case for subtract
		result = left - right;
		break;
	case 2://Case for multiplication
		result = left * right; 
		break;
	case 3://Case for divide
		result = left / right;
		break;
	}
	numbers.push(result);//Pushes result on to the stack.
}
