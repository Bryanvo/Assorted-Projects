// ITP 365 Spring 2016
// HW5 Vector and Poker Hands
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#include "console.h"
#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
	ITPVector<int> testVector;
	// TODO: Do stuff
	int userChoice;
	int num;
	bool cont = false;
	//Opens interface for user to select to test ITPVector or to play poker. 
	std::cout << "1. Test ITPVector" << std::endl;
	std::cout << "2. Poker Hands" << std::endl;
	std::cout << ">";
	std::cin >> userChoice;
	switch (userChoice)
	{
		//Case one for testing
	case 1:
		std::cout << "***Constructing an ITPVector***" << std::endl;
		std::cout << "Contents: " << testVector << std::endl;
		std::cout << "Capacity: " << testVector.capacity() << " ," << "Size: " << testVector.size() << std::endl;
		std::cout << "Enter a number of elements to add: ";
		std::cin >> num;
		//Loops through vector to insert numbers
		for (int i = 0; i < num; i++)
		{
			testVector.insert_back(num);
		}
		std::cout << "Content: " << testVector << std::endl;
		std::cout << "The back element is: " << testVector.get_back() << std::endl;
		std::cout << "Called remove_back" << std::endl;
		testVector.remove_back();
		std::cout << "Contents: " << testVector << std::endl;
		std::cout << "Capacity: " << testVector.capacity() << " ," << "Size: " << testVector.size() << std::endl;
		std::cout << "Test Complete!";
		break;
		//Case 2 for poker
	case 2:
		while (!cont)
		{
			std::string choice;
			ITPVector<Card> stack;
			createDeck(stack);//Creates deck
			PokerHand cards(stack);
			std::cout << "You drew :";
			std::cout << cards << std::endl;
			std::cout << cards.getBestPokerHand() << std::endl;
			std::cout << "Try again (y/n): ";
			std::cin >> choice;
			if (choice == "n" || choice == "N")
			{
				cont = false;
			}
		}
		break;
		//Default case in case of invalid entry. 
	default:
		error("Error: Invalid entry");
		break;

	}
	return 0;
}
