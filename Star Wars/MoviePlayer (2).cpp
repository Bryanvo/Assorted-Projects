// ITP 365 Fall 2014
// HW6 - Doubly Linked List and Movie Player
// Name: Bryan Vo
// Email: bryan@usc.edu
// Platform: Windows
#include "MoviePlayer.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    // TODO: Implement
	currFrameNum = 1;

	mFilmName = filmName;

	mFilm.clear();

	loadTape();
	
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    // TODO: Implement
	mFilm.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    // TODO: Implement
	//Conditional to test if there is a next node that mFilm's mCurr can be moved to
	if (mFilm.has_next())
	{
		mFilm.move_next();
		currFrameNum++;//currFrameNum is incremented

	}
	
	
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    // TODO: Implement
	//Conditional to test if there is a back node that mFilm's mCurr can be moved to
	if (mFilm.has_prev())
	{
		mFilm.move_prev();
		currFrameNum--;//currFrameNum is decremented
	}

		
	
	
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    // TODO: Implement
	mFilm.reset();
	currFrameNum = 1;
	//Conditionals to make sure currFrameNum does not go beyond zero
	if (currFrameNum <= 1)
	{
		currFrameNum = 1;
	}
	else
	{
		currFrameNum--;
	}
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    // TODO: Implement
    return mFilm.get_at_curr(); // FIX RETURN VALUE
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    // TODO: Implement
	
	//Deletes the current frame
	mFilm.remove_at_curr();
	//Moves forward to the next one
	mFilm.move_next();
	if (currFrameNum <= 0)
	{
		currFrameNum = 1;
	}
	else 
	{
		currFrameNum--;
	}
	
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
    // TODO: Implement
	mFilm.add_at_curr(getCurrFrame());
	currFrameNum++;
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    // TODO: Implement
    return currFrameNum; // FIX RETURN VALUE
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    // TODO: Implement
	return mFilm.size();
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    // TODO: Implement
	return FRAMESIZE;
}

// Function: getCurrFrame
// Purpose: Retrieves the current "frame" from the film list
// Modifies the inputted vector of GLabels to contain the current frame
// Input: A vector of "GLabels" that are the "screen" -- passed by reference
// Returns: Nothing
void MoviePlayer::getCurrFrame(Vector<GLabel*>& screen)
{
    // TODO: Implement
	std::string line = getCurrFrame();
	std::istringstream strStream(line);

	//For loop runs 13 times or the interger framesize
	for (int i = 0; i < FRAMESIZE; i++)
	{
		std::string temp = "";
		std::getline(strStream, temp);
		screen[i]->setLabel(temp);
	}
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    // TODO: Implement
	
	std::ifstream fileStream(mFilmName);

	//If file is open
	if (fileStream.is_open())
	{
		int count = 0;
		//Loop until end of file
		while (!fileStream.eof())
		{
			std::string line, num, separator = "";
			int time = 0;
			std::getline(fileStream, separator);
			std::stringstream strStream(separator);
			strStream >> time; 
			num = "";
			//Takes in the 13 lined screen through a loop
			for (int i = 0; i < FRAMESIZE; i++)
			{
				std::getline(fileStream, line);
				num += line + " \n";
			}
			//Insert backs num into mfilm
			for (int i = 0; i < time; i++)
			{
				mFilm.insert_back(num);
			}
		}
	}
	else 
	{
		error("Error has occured");
	}

}