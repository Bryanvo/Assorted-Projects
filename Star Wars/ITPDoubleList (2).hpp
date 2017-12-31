// ITP 365 Fall 2014
// HW6 - Doubly Linked List and Movie Player
// Name: Bryan Vo
// Email: bryan@usc.edu
// Platform: Windows
//
// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection
//

#pragma once
#include "error.h"
#include <ostream>
#include <sstream>
#include "leaker.h"

template <typename T>
struct Node
{
	// Data in this node
	T mData;
	// Link to previous node
	Node* mPrev;
	// Link to next node
	Node* mNext;
};

template <typename T>
class ITPDoubleList
{
public:
	// Function: Default Constructor
	// Purpose: Initializes size to 0 and head/tail to null
	// Input: None
	// Returns: Nothing
	ITPDoubleList()
	{
		mSize = 0;
		mHead = nullptr;
		mTail = nullptr;
		mCurr = nullptr;
	}

	// Function: Destructor
	// Purpose: Calls the clear function to delete the list
	// Input: None
	// Returns: Nothing
	~ITPDoubleList()
	{
		clear();
	}

	// Function: Copy Constructor
	// Purpose: Initializes this list as a deep copy of other
	// Input: Other list to copy (const reference)
	// Returns: Nothing
	ITPDoubleList(const ITPDoubleList& other)
	{
		// TODO: Implement
		//1. Set size to 0, head to null, tail to null
		mSize = 0;
		mHead = nullptr;
		mTail = nullptr;
		//2. Create a temp that points to the head node in “other”
		Node<T>* temp = other.mHead;
		//3. While temp is not null…
		//				1. Insert_back temp’s data into this list
		//				2. Advance temp to the next node
		while (temp != nullptr)
		{
			insert_back(temp->mData);
			temp = temp->mNext;
		}
	}

	// Assignment Operator
	// Function: Assignment Operator
	// Purpose: Clear this list, and then make a deep copy of other
	// Input: Other list to copy (const reference)
	// Returns: *this
	ITPDoubleList& operator=(const ITPDoubleList& other)
	{
		// TODO: Implement
		//1. Call clear (to clear out any values already in this list)
		clear();
		//2. Create a temp that points to the head node in “other"
		Node<T>* temp = other.mHead;
		//3. While temp is not null…
		//	1. Insert_back temp’s data into this list
		//	2. Advance temp to the next node
		while (temp != nullptr)
		{
			insert_back(temp->mData);
			temp = temp->mNext;
		}
		//4. By convention, operator= returns *this
		return *this;
	}

	// Function: clear
	// Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
	// Input: None
	// Returns: Nothing
	void clear()
	{
		// TODO: Implement
		//1. While size > 0…
		//			a) Call remove_front
		while (mSize > 0)
		{
			remove_front();
		}
	}

	// Function: size
	// Purpose: Gets the current size of the linked list
	// Input: None
	// Returns: size of the list
	unsigned size() const
	{
		// TODO: Implement
		return mSize; ////Returns Size
	}

	// Function: insert_front
	// Purpose: Inserts a node to the front of the linked list
	// Input: Value to store in the new node
	// Returns: Nothing
	void insert_front(const T& value)
	{
		// TODO: Implement
		//1. Dynamically allocate a new node
		//			a) Set its data to the value
		//			b) Set its previous to null(since this will be the new head)
		//			c) Set its next to the current head
		Node<T>* newNode = new Node<T>();
		newNode->mData = value;
		newNode->mPrev = nullptr;
		newNode->mNext = mHead;
		//2. If the size is 0…The tail is the new node
		if (mSize == 0)
		{
			mTail = newNode;
		}
		//3. Otherwise…set the previous of the current head to the new node
		else
		{
			mHead->mPrev = newNode;

		}
		//4. Set the head to the new node
		mHead = newNode;
		//5. Increment the size
		mSize++;
	}

	// Function: get_front
	// Purpose: Gets the value of the node at the front of the list
	// Input: None
	// Returns: Value of the node at the front of the list
	T& get_front()
	{
		// TODO: Implement
		//1. If the size is 0, error!
		if (mSize == 0)
		{
			error("Error size is 0");
		}
		//2. Return the data at the head node
		return mHead->mData;
	}

	// Function: remove_front
	// Purpose: Removes the node at the front of the list
	// Input: None
	// Returns: None
	void remove_front()
	{
		// TODO: Implement
		//1. If the size is 0…error!
		if (mSize == 0)
		{
			error("Error size is 0");
		}
		//2. Otherwise if the size is 1…
		//			1. Delete the head node
		//			2. Set head and tail to null, size to 0
		else if (mSize == 1)
		{
			delete mHead;
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		//3. Otherwise…
		else
		{
			//1. Set a temp equal to the next node after head
			Node<T>* tempNode = mHead->mNext;
			//2. Delete the head node
			delete mHead;
			//3. The new head is temp
			mHead = tempNode;
			//4. The new head previous is now null
			mHead->mPrev = nullptr;
			//5. Decrement size
			mSize--;
		}

	}

	// Function: insert_back
	// Purpose: Inserts a node to the back of the linked list
	// Input: Value to store in the new node
	// Returns: Nothing
	void insert_back(const T& value)
	{
		// TODO: Implement
		//1. Dynamically allocate a new node
		Node<T>* newNode = new Node<T>();
		//a) Set its data to the value
		newNode->mData = value;
		//b) Set its previous to the current tail
		newNode->mPrev = mTail;
		//c) Set the next to null (since this will be the new tail)
		newNode->mNext = nullptr;

		//2. If the size is 0…The head is the new node
		if (mSize == 0)
		{
			mHead = newNode;
		}
		//3. Otherwise…set the next of the current tail to the new node
		else
		{
			mTail->mNext = newNode;
		}
		//4. Set the tail to the new node
		mTail = newNode;
		//5. Increment the size
		mSize++;


	}

	// Function: get_back
	// Purpose: Gets the value of the node at the back of the list
	// Input: None
	// Returns: Value of the node at the back of the list
	T& get_back()
	{
		//1. If the size is 0, error!
		if (mSize == 0)
		{
			error("Error size is 0");
		}
		//2. Return the data at the tail node
		return mTail->mData;
	}

	// Function: remove_back
	// Purpose: Removes the node at the back of the list
	// Input: None
	// Returns: Nothing
	void remove_back()
	{
		// TODO: Implement
		//1. If the size is 0…error!
		if (mSize == 0)
		{
			error("Error size is 0");
		}
		//2. Otherwise if the size is 1…
		else if (mSize == 1)
		{
			delete mTail;
			mHead = nullptr;
			mTail = nullptr;
			mSize = 0;
		}
		//3. Otherwise…
		else
		{
			//1. Set a temp equal to the previous node before the tail
			Node<T>* temp = mTail->mPrev;
			//2. Delete the tail node
			delete mTail;
			//3. The new tail is temp
			mTail = temp;
			//4. The new tail next is now null
			mTail->mNext = nullptr;
			//5. Decrement size
			mSize--;
		}


	}

	// Function: reset
	// Purpose: Moves the current "read" pointer to the beginning of the list
	// Input: None
	// Returns: Nothing
	void reset()
	{
		// TODO: Implement
		mCurr = mHead;

	}

	// Function: has_next
	// Purpose: Checks to see if there is another node after the currently read node
	// Input: None
	// Returns: True to indicate there is another valid node to read
	bool has_next()
	{
		// TODO: Implement
		//Conditional to test if there is a node after mCurr
		if (mCurr->mNext != nullptr)
		{
			return true;
		}

		return false;
	}

	// Function: has_prev
	// Purpose: Checks to see if there is another node after the currently read node
	// Input: None
	// Returns: True to indicate there is another valid node to read
	bool has_prev()
	{
		// TODO: Implement
		//Conditional to test if there is a node before mCurr
		if (mCurr->mPrev != nullptr)
		{
			return true;
		}
		return false;
		// FIX RETURN VALUE	}
	}

	// Function: move_next
	// Purpose: Moves the reading pointer to the next node
	// Input: None
	// Returns: Nothing
	void move_next()
	{
		// TODO: Implement
		//Conditional to test if mCurr can actually be moved to a node.
		if (has_next())
		{
			//moves mCurr forward to the next node
			mCurr = mCurr->mNext;
		}
	}

	// Function: movePrev
	// Purpose: Moves the reading pointer to the previous node
	// Input: None
	// Returns: Nothing
	void move_prev()
	{
		// TODO: Implement
		//Conditional to test if mCurr can actually be moved to a node.
		if (has_prev())
		{
			//moves mCurr forward to the node before it.
			mCurr = mCurr->mPrev;
		}
	}

	// Function: get_at_curr
	// Purpose: Gets the value of the node at the current reader pointer
	// Input: None
	// Returns: Value of the node at the reader pointer
	T& get_at_curr()
	{
		// TODO: Implement
		//Conditional to test if the linked list's size is zero
		if (mSize == 0)
		{
			error("Error: Size is 0");
		}
		//Returns mCurr's data
		return mCurr->mData; // FIX RETURN VALUE
	}

	// Function: add_at_curr
	// Purpose: Inserts a node at the current reader location in the list
	// Input: Value to store in the new node
	// Returns: Nothing
	void add_at_curr(const T& value)
	{
		// TODO: Implement
		//If mCurr is at the head, insert_front is called
		if (mCurr == mHead)
		{
			insert_front(value);
		}
		// Otherwise, the node is inserted in between mCurr and its mPrev
		else
		{
			//A new node is dynamically allocated
			Node<T>* add = new Node<T>();

			//Two pointers are created to point to the node before
			//and after the insertion location
			Node<T>* beforeptr = mCurr->mPrev;
			Node<T>* afterptr = mCurr;
			//The newNode Add takes in the value
			add->mData = value;
			//Add's next is set to the after node
			add->mNext = afterptr;
			//Add's previous is set to the before node.
			add->mPrev = beforeptr;
			//The node before the insertion point is set to add
			beforeptr->mNext = add;
			//The node after the insertion point is set to add
			afterptr->mPrev = add;
			//Size is then incremented
			mSize++;
		}

	}

	// Function: remove_at_curr
	// Purpose: Removes the node pointed to by the current read pointer
	// Input: None
	// Returns: Nothing
	void remove_at_curr()
	{

		// TODO: Implement
		if (mSize == 0)
		{
			error("Error size is 0");
		}
		//If there are actually nodes on the list to be removed
		else if (mSize > 0)
		{
			//If mCurr is equal to mHead, then remove front is called.
			if (mCurr == mHead)
			{
				remove_front();
				//mCurr is then reset
				reset();
			}
			//Otherwise if mCurr is equal to mTail, remove_back is called.
			else if (mCurr == mTail)
			{
				remove_back();
				reset();
			}
			//Otherwise . . .
			else
			{
				//Two pointers are created to point to the node after mCurr,
				//and before mCurr
				Node<T>* beforeptr = mCurr->mPrev;
				Node<T>* afterptr = mCurr->mNext;
				//The after node's prev is set to point to the before node
				afterptr->mPrev = beforeptr;
				//The before node's next is set to point to after node.
				beforeptr->mNext = afterptr;
				//mCurr is deleted
				delete mCurr;
				//size is then decremented.
				mCurr = afterptr;
				//size is then decremented.
				mSize--;

			}
		}

	}

private:
	// Pointer to the head node
	Node<T>* mHead;
	// Pointer to the tail node
	Node<T>* mTail;
	// Pointer to current node
	Node<T>* mCurr;
	// Number of nodes currently in the list
	unsigned mSize;

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !!!! DO NOT EDIT BELOW THIS LINE !!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
public:
	// Function: Output Stream Operator
	// Purpose: Prints the contents of the list to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, list to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
	{
		os << "{";

		Node<T>* temp = list.mHead;
		while (temp != nullptr)
		{
			os << temp->mData;
			if (temp != list.mTail)
			{
				os << ",";
			}

			temp = temp->mNext;
		}

		os << "}";
		return os;
	}

	// Function: toString
	// Purpose: Converts list to a string
	// Input: None
	// Output: String (in the format as the ostream)
	std::string toString() const
	{
		std::stringstream str;
		str << *this;
		return str.str();
	}

	// Function: toReverseString
	// Purpose: Outputs the list in reverse
	// Input: None
	// Output: String in reverse
	std::string toReverseString() const
	{
		std::stringstream str;

		str << "{";

		Node<T>* temp = mTail;
		while (temp != nullptr)
		{
			str << temp->mData;
			if (temp != mHead)
			{
				str << ",";
			}

			temp = temp->mPrev;
		}

		str << "}";

		return str.str();
	}
};
