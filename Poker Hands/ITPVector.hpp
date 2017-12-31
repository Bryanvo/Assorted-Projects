// ITP 365 Spring 2016
// HW5 Vector and Poker Hands
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: Windows
//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
		// TODO: Implement
		mSize = 0;
		mCapacity = INITIAL_CAPACITY;
		mData = new T[mCapacity];

	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
		// TODO: Implement
		delete[] mData;
		mData = nullptr;
		mCapacity = 0;
		mSize = 0; 

	}

	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		// TODO: Implement
		return mCapacity; // FIX RETURN VALUE
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
		// TODO: Implement
		return mSize; // FIX RETURN VALUE
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
		// TODO: Implement
		if (index > mSize - 1 || index < 0)
		{
			error ("Error, index out of range");
		}

			return mData[index]; // FIX RETURN VALUE
		
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
		// TODO: Implement
		if (index > mSize - 1 || index < 0)
		{
			error("Error, index out of range");
		}

		return mData[index]; // FIX RETURN VALUE
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void insert_back(const T& value)
	{
		// TODO: Implement
		//If the current size is less than the capacity, 
		// places an element at index size and then increments by 1
		if (mSize < mCapacity)
		{
			mData[mSize] = value;
			mSize++;
		}
		//If size is equal to capacity, the lower algorithm is followed
		if (mSize == mCapacity)
		{
				/*1. Increase the capacity(usually double it)
				2. Dynamically allocate a new underlying array w / new capacity
				3. Copy the data from the old array to the new array
				4. Delete the old array
				5. Set your pointer to the new array
				6. Add an element at index size
				7. Increment size by 1*/
		//1.	
			mCapacity = mCapacity * CAPACITY_MULTIPLIER;
		//2
			T* Temp = new T[mCapacity];
		//3
			for (int i = 0; i < mSize; i++)
			{
				Temp[i] = mData[i];
			}
		//4
			delete mData;
		//5
			mData = Temp;
		//6
			Temp[mSize] = value;
		//7
			mSize++;
		}
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& get_back()
	{
		// TODO: Implement
		if (mSize == 0)
		{
			error("error");
		}
		else
		{
			return mData[mSize - 1];
		}
		
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void remove_back()
	{
		// TODO: Implement
		if (mSize == 0)
		{
			error("Error");
		}
		mSize--;
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
		// TODO: Implement

		os << "{";
		for (unsigned int i = 0; i < vector.size(); i++)
		{
			if (i == vector.size() - 1)
			{
				os << vector[i];
			}
			else
			{
				os << vector[i] << " , ";
			}
		}
		os << "}";
		return os;
	}
private:
	// TODO: Define member variables here
	unsigned int mCapacity;
	unsigned int mSize;
	T* mData;
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// NOTE: Do not edit code below this line!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Disallow assignment and copy construction
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{

	}

	ITPVector(const ITPVector<T>& other)
	{

	}
};
