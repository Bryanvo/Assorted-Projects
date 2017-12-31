// ITP 365 Fall 2015
// HW4 - Wedding Planner
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows

#include "Hevent.h"
#include <iostream>
#include "Hcal.h"
#include <fstream>
#include "strlib.h"
#include "map.h"

//Function: loadCal
//Purpose:This function will read in the .csv file, create the appropriate holiday events,
//and load them into a calendar
//Input: std::string of the file's name
//Output: pointer to a hcal
hcal* loadCal(std::string fileName)
{
	hcal* ptr = new hcal;
	unsigned long long x = 0;
	std::string Htype = "";
	std::string line = "";
	char coma; 
	std::string Input;
	std::ifstream fileInput(fileName);
	if (fileInput.is_open())
	{
		std::getline(fileInput, line);
		while (fileInput.eof()!= true)
		{
			std::getline(fileInput, line);
			std::istringstream stream(line);
			stream >> x;
			stream >> coma;
			std::getline(stream, line, ',');
			std::getline(stream, Htype);
			hevent* event = new hevent(x, line, Htype);
			ptr->addEvent(event);
		}
	}
	return ptr; 
}

// Function: hcal* merge
//Purpose:Merges csv files into a new hcal
//Input: two hcal pointers
//Output: returns pointer to newl merged hcal
hcal* merge(hcal* a, hcal* b)
{
	//Dynamically create a new HCal. This will be the value we return.
	hcal* C = new hcal;
	int i = 0;
	int j = 0;
	// This loop that executes while i and j are within range (before the ends of their
//respective calendars).
	while(i < a->getVecSize() && j < b->getVecSize())
	{
		//If the HEvent at A[i] occurs before the HEvent at B[j] add A[i] to the end of C.
			//Then increment i.
		if(*(a->getHevent(i)) < *(b->getHevent(j)))
		{
			C->addEvent(a->getHevent(i));
			i++;
		}
		//If not add event at B[j] to the end of C. Then increment j
		else
		{
			C->addEvent(b->getHevent(j));
			j++;
		}
	}
	//When the above loop is over there will be a portion of either A or B left over(it hasnft
	//	been added to C).If A has items remaining, this conditional adds them to the end of C.If B has items
	//remaining adds them to the end of C.

	if (a->getVecSize() > i)
	{
		for (int k = i; k < a->getVecSize(); k++)
		{
			C->addEvent(a->getHevent(k)); 
		}
		
	}
	else if (b->getVecSize() > j)
	{
		for (int k = j; k < b->getVecSize(); k++)
		{
			C->addEvent(a->getHevent(k));
		}
	}
	
	return C;
}


int main(int argc, char** argv)
{
	// TODO: Implement stuff
	//Intialization list
	std::string userChoice, day, month, year;//Strings that represent separated user input date. 
	std::string stop = "q";
	unsigned int dayI, monthI, yearI; //Ints that represent date
	//hcal pointers
	hcal* A = new hcal;
	hcal* B = new hcal;
	hcal* C = new hcal;
	hcal* D = new hcal;
	hcal* E = new hcal;
	hcal* mergeCal = new hcal;
	//Calls loadCal to store inside pointers
	A = loadCal("CHholiday2016.csv");
	B = loadCal("BRholiday2016.csv");
	C = loadCal("USholiday2016.csv");
	//Merges calendars
	D = merge(A, B);
	E = merge(C, D);

	//Prompts user
	std::cout << "Welcome to the wedding planner!" << std::endl;
	
	//Beginning of while loop.
	bool end = false;
	while (!end)//While loop runs as long as end does not equal true. 
	{
		std::cout << "Please enter a date (MM/DD/YYYY): ";
		std::cin >> userChoice;
		//Quits loop and exits program. 
		if (userChoice == stop)
		{
			std::cout << "Quiting!" << std::endl;
			end = true;
			return 0;
		}
		//Separates the user's input date into separate numbers
		int index = userChoice.find("/", 0);
		month = userChoice.substr(0, 2);
		day = userChoice.substr(index + 1, 2);
		index = userChoice.find("/", 3);
		year = userChoice.substr(index + 1, 4);

		//converts userInput string to intergers
		monthI = stringToInteger(month);
		dayI = stringToInteger(day);
		yearI = stringToInteger(year);

		int convert = 0;
		int GMTWO = 0;

		//Conditional for non-daylight savings holidays, converts epochseconds to GMT
		if (monthI < 3 || monthI > 11)
		{
			convert = getEpochSecs(monthI, dayI, yearI);
			GMTWO = convert - 28800;
		}

		//Conditional for daylight savings holidays, converts epochseconds to GMT and accounts for hour shift. 
		if (monthI > 3 && monthI < 11)
		{
			convert = getEpochSecs(monthI, dayI, yearI);
			GMTWO = convert - 25200;
		}

		//Conditional for holidays on start of daylight savings
		if (monthI == 3)
		{
			if (dayI < 13)
			{
				convert = getEpochSecs(monthI, dayI, yearI);
				GMTWO = convert - 28800;
			}
			else
			{
				convert = getEpochSecs(monthI, dayI, yearI);
				GMTWO = convert - 25200;
			}
		}

		//Conditional for holidays at the end of daylight savings
		if (monthI == 11)
		{
			if (dayI > 6)
			{
				convert = getEpochSecs(monthI, dayI, yearI);
				GMTWO = convert - 28800;
			}
			else
			{
				convert = getEpochSecs(monthI, dayI, yearI);
				GMTWO = convert - 25200;
			}
		}

		//dynamically allocates hevent
		hevent* weddingday = new hevent(GMTWO, "wedding day", "love");
		
		//conditional if no holiday is found. 
		if (E->search(weddingday) == -1)
		{
			std::cout << "That is a great day for a wedding!" << std::endl;
		}

		//Outputs holiday name if one is found.
		else
		{
			std::cout << *(E->getHevent(E->search(weddingday))) << std::endl;
		}
	}
	//Clears memory
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete mergeCal;
	A = nullptr;
	B = nullptr;
	C = nullptr;
	D = nullptr;
	E = nullptr;
	mergeCal = nullptr;

	return 0;
}
