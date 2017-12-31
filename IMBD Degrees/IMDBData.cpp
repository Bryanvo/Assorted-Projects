// ITP 365 Spring 2016
// HW7 - IMDB Graph
// Name: Bryan Vo
// Email: bryanvo@usc.edu
// Platform: windows
//
// IDMBData.cpp - Implements IMDBData interface

#include "IMDBData.h"
#include <fstream>
#include <iostream>
#include <queue>

// Do for Part 1
// Function: Default Constructor
// Purpose: Loads in the actor/movie file specified,
// and populates the data into the appropriate hash maps.
// Also constructs the graph with actor relationships.
// Input: Name of file to load (by reference)
// Returns: Nothing
IMDBData::IMDBData(const std::string& fileName)
{
	// TODO for Part 1
	// TODO: Generate the actor to movies map
	//member variables
	std::ifstream file(fileName);
	std::string tempLine, tempActor, tempMovie;
	std::vector<std::string> VecMov;
	//checks to see if file is open
	if (file.is_open()) 
	{
		//runs while file is open
		while (!file.eof()) 
		{
			// Grabs first line
			std::getline(file, tempLine);

			//checks if line has "|" to distinguish movie or actor.
			if (tempLine[0] != '|')
			{
				//if line doesn't adds an actor and its movie vector to a map
				mActorsToMoviesMap.insert(std::make_pair(tempActor, VecMov));
				// TODO: Generate the movie to actors map
				reverseMap(tempActor, VecMov);
				VecMov.clear();
				tempActor = tempLine;
			}
			else
			{
				//else adds the movie to the actor's vector
				tempMovie = tempLine.substr(1);
				VecMov.push_back(tempMovie);
			}
		}
	}
	else
	{
		std::cout << "Error: No file was found" << std::endl;
	}
}

// Do for Part 1
// Function: reverseMap
// Purpose: This is a helper function that is used to generate
// the reverse map (movies to actors)
// Input: Name of actor (by reference), vector of their movies (by reference)
// Returns: Nothing
void IMDBData::reverseMap(const std::string& actorName, const std::vector<std::string>& movies)
{
	for (int i = 0; i < movies.size(); i++)
	{
		//If mMovieToActorsMap already contains the movie in question, add actorName to that movie’s associated vector
		if (mMoviesToActorsMap.find(movies[i]) != mMoviesToActorsMap.end())
		{
			mMoviesToActorsMap[movies[i]].push_back(actorName);
		}
		else
		{
			//Otherwise, add an entry in mMovieToActorsMap that associates the movie with a vector that, for now, only contains actorName
			std::vector<std::string> actors;//create a vector of strings(of actor names)
			actors.push_back(actorName);
			mMoviesToActorsMap.emplace(movies[i], actors);
		}
	}
}

// Do for Part 1
// Function: getMoviesFromActor
// Purpose: Given an actor's name, returns a vector containing their movies
// Input: Name of actor (by reference)
// Returns: Vector of movies (by reference)
std::vector<std::string>& IMDBData::getMoviesFromActor(const std::string& actorName)
{
	//If the actor to movies map contains the actorName key specified, this function will return the lookup of the map.
	if (mActorsToMoviesMap.find(actorName) != mActorsToMoviesMap.end())
	{
		return mActorsToMoviesMap[actorName];
	}
	else
	{
		return sEmptyVector;
	}

}

// Do for Part 1
// Function: getActorsFromMovie
// Purpose: Given a movie's name, returns the name of its actors
// Input: Name of movie (by reference)
// Returns: Vector of actors (by reference)
std::vector<std::string>& IMDBData::getActorsFromMovie(const std::string& movieName)
{
	if (mMoviesToActorsMap.find(movieName) != mMoviesToActorsMap.end())
	{
		return mMoviesToActorsMap[movieName];
	}
	else
	{
		return sEmptyVector;
	}
}

// Do for Part 2
// Function: findRelationship
// Purpose: Tries to find a relationship between two actors, using a BFS
// and outputs (to cout) the result of the search.
// Input: Name of two actors to check for a relationship
// Returns: Nothing
void IMDBData::findRelationship(const std::string& fromActor, const std::string& toActor)
{
	//creates a queue of ActorNode pointers
	std::queue<ActorNode*> actorsList;
	//startNode is the ActorNode in the mGraph with name same as the name of fromActor
	ActorNode* startNode = mGraph.getActorNode(fromActor);
	//targetNode is the ActorNode in the mGraph with name same as the name of toActor
	ActorNode* toNode = mGraph.getActorNode(toActor);
	ActorNode* currentNode;
	bool path = false;
	//enqueue the node we start from
	actorsList.emplace(startNode);
	// check that the two actors passed to the relationship test, if not error is outputed
	if (mGraph.containsActor(fromActor) == true && mGraph.containsActor(toActor) == true)
	{
		while (!actorsList.empty())
		{
			//dequeue the front ActorNode, and save in currentNode
			currentNode = actorsList.front();
			actorsList.pop();
			//If currentNode == targetNode, a path is found
			if (currentNode == toNode)
			{
				//set pathFound to "true" to indicate we've found a path
				path = true;
			}
			//Otherwise if currentNode’s bool is false . . .
			else if (currentNode->mIsVisited == false)
			{
				//Go to currentNode, and set currentNode visited to true
				currentNode->mIsVisited = true;
				//range-based for loop loops through currentNode's adjacency list 
				for (Edge* AdjacentNode : currentNode->mEdges)
				{
					if (AdjacentNode->mOtherActor->mIsVisited == false)
					{
						//enqueue the adjacent node
						actorsList.emplace(AdjacentNode->mOtherActor);

						if (AdjacentNode->mOtherActor->mPath.size() == 0)
						{
							//Set the adjacent node’s path equal to currentNode’s path
							AdjacentNode->mOtherActor->mPath = currentNode->mPath;
							//use PathPair to make a path with adjacent nodes’s relevant path information
							PathPair path(AdjacentNode->mMovieName, AdjacentNode->mOtherActor->mName);
							//push_back adjacent nodes’s path information
							AdjacentNode->mOtherActor->mPath.push_back(path);
						}
					}
				}
			}
		}
	}
	else
	{
		// if two actors passed to findRelationship are not in the graph, an error message will appear
		std::cout << "error: No actor was found" << std::endl;
	}
	//if a path is found
	if (path)
	{
		std::cout << "Found a path!" << std::endl;
		//start from the fromActor
		std::cout << startNode->mName << " was in..." << std::endl;
		int i = 1;
		//use range-based loop to loop through the mPath list of the target ActorNode, and show the path to the user 
		for (const PathPair path : toNode->mPath)
		{
	
			if (i<toNode->mPath.size())
			{
				std::cout << path.getMovieName() << " with " << path.getActorName() << " who was in..." << std::endl;
			}
			
			else
			{
				std::cout << path.getMovieName() << " with " << path.getActorName() << std::endl;
			}
			i++;
		}
	}
	else
	{
		std::cout << "Didn't find a path" << std::endl;
	}

	mGraph.clearVisited();
}

// For Part 2
// Function: createGraph
// Purpose: This helper function constructs the IMDBGraph from the movie to actors map
// Input: None
// Returns: Nothing
void IMDBData::createGraph()
{
	// DO NOT EDIT THIS FUNCTION
	// For every movie in the actors map...
	for (auto& p : mMoviesToActorsMap)
	{
		const std::string& movieName = p.first;
		// Get the actors for this movie
		const std::vector<std::string>& actors = mMoviesToActorsMap[movieName];

		// Make n^2 edges between these actors
		for (size_t i = 0; i < actors.size(); i++)
		{
			ActorNode* firstActor = mGraph.getActorNode(actors[i]);
			for (size_t j = i + 1; j < actors.size(); j++)
			{
				ActorNode* secondActor = mGraph.getActorNode(actors[j]);
				mGraph.createActorEdge(firstActor, secondActor, movieName);
			}
		}
	}
}

// Leave here! Do not edit!!! Use in part 1
// DO NOT REMOVE THIS LINE
std::vector<std::string> IMDBData::sEmptyVector;

