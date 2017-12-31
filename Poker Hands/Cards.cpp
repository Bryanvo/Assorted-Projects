// ITP 365 Spring 2016
// HW5 Vector and Poker Hands
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows
//
// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"
#include <random>
#include <algorithm>
#include <string>
#include <iostream>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
	// TODO: Implement
	for (int i = 0; i < 5; i++)
	{
		//Draws 5 cards and stores them in the mHand member variable
		mHand.insert_back(deck.get_back());
		deck.remove_back();
	}
	// Sort the hand
	std::sort(&mHand[0], &mHand[0] + mHand.size());
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
	// TODO: Implement
	std::string retVal;
	if (hasFlush() == true && hasStraight() == true)
	{
		retVal = "You have a straight flush";
		return retVal;
	}
	else if (hasFourOfAKind() == true)
	{
		retVal = "You have a four of a kind";
		return retVal;
	}
	else if (hasFullHouse() == true)
	{
		retVal = "You have a full house";
		return retVal;
	}
	else if (hasFlush() == true)
	{
		retVal = "You have a flush";
		return retVal;
	}
	else if (hasStraight() == true)
	{
		retVal = "You have a straight";
		return retVal;
	}
	else if (hasThreeOfAKind() == true)
	{
		retVal = "You have a three of a kind";
		return retVal;
	}
	else if (hasTwoPairs() == true)
	{
		retVal = "You have a two pairs";
		return retVal;
	}
	else if (hasPair() == true)
	{
		retVal = "You have a pair";
		return retVal;
	}
	else
	{
		return "high card"; // FIX RETURN VALUE
	}
	
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
	bool retVal = false;
	
	// TODO: Implement
	if (mHand[0].mRank == (mHand[1].mRank - 1) &&
		mHand[1].mRank == (mHand[2].mRank - 1) &&
		mHand[2].mRank == (mHand[3].mRank - 1) &&
		mHand[3].mRank == (mHand[4].mRank - 1))
	{
		retVal = true;
	}

	return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
	bool retVal = false;
	
	// TODO: Implement
	if (mHand[0].mSuit == mHand[1].mSuit &&
		mHand[1].mSuit == mHand[2].mSuit &&
		mHand[2].mSuit == mHand[3].mSuit &&
		mHand[3].mSuit == mHand[4].mSuit)
	{
		retVal = true;
	}
	return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x x y
	// or
	// x y y y y
	bool retVal = false;

	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[1].mRank == mHand[2].mRank &&
		mHand[2].mRank == mHand[3].mRank)
	{
		retVal = true;
	}

	if (mHand[1].mRank == mHand[2].mRank &&
		mHand[2].mRank == mHand[3].mRank &&
		mHand[3].mRank == mHand[4].mRank)
	{
		retVal = true;
	}

	return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x y y
	// or
	// x x y y y
	bool retVal = false;
	
	// TODO: Implement

	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[1].mRank == mHand[2].mRank &&
		mHand[3].mRank == mHand[4].mRank)
	{
		retVal = true;
	}

	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[2].mRank == mHand[3].mRank &&
		mHand[3].mRank == mHand[4].mRank)
	{
		retVal = true;
	}

	return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	// There are three possibilities:
	// x x x y z
	// x y y y z
	// x y z z z

	bool retVal = false;
	
	// TODO: Implement
	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[1].mRank == mHand[2].mRank &&
		mHand[3].mRank != mHand[4].mRank)
	{
		retVal = true;
	}

	if (mHand[0].mRank != mHand[4].mRank &&
		mHand[1].mRank == mHand[2].mRank &&
		mHand[2].mRank == mHand[3].mRank)
	{
		retVal = true;
	}
	
	if (mHand[0].mRank != mHand[1].mRank &&
		mHand[2].mRank == mHand[3].mRank &&
		mHand[3].mRank == mHand[4].mRank)
	{
		retVal = true;
	}
	return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
	// There are three possibilities:
	// x x y y z
	// x y y z z
	// x x y z z
	bool retVal = false;
	
	// TODO: Implement
	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[1].mRank != mHand[2].mRank &&
		mHand[2].mRank == mHand[3].mRank &&
		mHand[3].mRank != mHand[4].mRank &&
		mHand[0].mRank != mHand[4].mRank)
	{
		retVal = true;
	}

	if (mHand[1].mRank != mHand[2].mRank &&
		mHand[1].mRank == mHand[0].mRank &&
		mHand[2].mRank != mHand[0].mRank &&
		mHand[3].mRank == mHand[1].mRank &&
		mHand[4].mRank != mHand[0].mRank)
	{
		retVal = true;
	}
	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[1].mRank != mHand[2].mRank &&
		mHand[2].mRank != mHand[3].mRank &&
		mHand[3].mRank == mHand[4].mRank &&
		mHand[0].mRank != mHand[4].mRank
		)
	{
		retVal = true;
	}
	return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
	// There's a pair if any neighbors are equal to each other
	bool retVal = false;
	if (mHand[0].mRank == mHand[1].mRank &&
		mHand[2].mRank != mHand[1].mRank &&
		mHand[2].mRank != mHand[3].mRank &&
		mHand[3].mRank != mHand[4].mRank)
	{
		retVal = true;
	}
	if (mHand[1].mRank == mHand[2].mRank &&
		mHand[1].mRank != mHand[0].mRank &&
		mHand[2].mRank != mHand[0].mRank &&
		mHand[3].mRank != mHand[1].mRank &&
		mHand[4].mRank != mHand[0].mRank)
	{
		retVal = true;
	}

	if (mHand[2].mRank == mHand[3].mRank &&
		mHand[0].mRank != mHand[1].mRank &&
		mHand[1].mRank != mHand[2].mRank &&
		mHand[3].mRank != mHand[4].mRank &&
		mHand[0].mRank != mHand[4].mRank)
	{
		retVal = true;
	}

	if (mHand[0].mRank != mHand[1].mRank &&
		mHand[1].mRank != mHand[2].mRank &&
		mHand[2].mRank != mHand[3].mRank &&
		mHand[3].mRank == mHand[4].mRank &&
		mHand[0].mRank != mHand[4].mRank)
	{
		retVal = true;
	}
	

	return retVal;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Do not edit code below this line!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
	for (int i = 0; i < 4; i++)
	{
		Suit suit = Suit(i);
		for (int value = 2; value <= 14; value++)
		{
			deck.insert_back(Card(value, suit));
		}
	}

	// Shuffle the deck
	std::shuffle(&deck[0], &deck[0] + deck.size(), std::random_device());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	// Output value
	if (card.mRank < 11) // Number card
	{
		os << card.mRank;
	}
	else // Face card
	{
		switch (card.mRank)
		{
		case 11:
			os << "Jack";
			break;
		case 12:
			os << "Queen";
			break;
		case 13:
			os << "King";
			break;
		case 14:
			os << "Ace";
			break;
		default:
			os << "Invalid";
			break;
		}
	}

	// Output suit
	os << " of ";
	switch (card.mSuit)
	{
	case CLUBS:
		os << "Clubs";
		break;
	case DIAMONDS:
		os << "Diamonds";
		break;
	case HEARTS:
		os << "Hearts";
		break;
	case SPADES:
		os << "Spades";
		break;
	default:
		os << "Invalid";
		break;
	}

	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
	// If their values are the same, compare the suits
	if (left.mRank == right.mRank)
	{
		return left.mSuit < right.mSuit;
	}
	else
	{
		return left.mRank < right.mRank;
	}
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
	os << hand.mHand;
	return os;
}
