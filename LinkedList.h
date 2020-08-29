#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
public:

	LinkedList();	//Default constructor sets head and tail both to nullptr.


	~LinkedList();	//Destructor


	LinkedList(const LinkedList& other);	//Copy constructor. Copies one LinkedList into another.


	bool is_empty() const;	//Determines if both head and tail are both set to nullptr of a list. Returns False if head and tail are not nullptr.

	LinkedList& operator=(const LinkedList& other);	//Copy Assignment. Completely copies over the values of other into the list calling the function.




	void insert(string ID, int YR, int MONTH, double TEMP);	 //Creates new pointer node from the passed in parameters and places into linked the list depending on its value.
							// Calls Node's < operator function and places that Node either before, after, or at the head, depending on if that Node's values are smaller than Node's already inserted in the list.

	void clear();	//Completely clears a linked list by deleting the nodes and setting head & tail to nullptr.

	// The functions below are written already. Do not modify them.
	std::string print() const;	//Prints out values of 
	int ModE(int hiR, int loR, string id);		//Returns the mode of int temperatures between the years hiR and loR that match the id passed in.
	double Average(int hiYr, int loYr, string id);	//Returns the average temperature between the years hiR and loR that match the id passed in.
	Node* getHead() const;	//Returns position (Pointer) of Head in linked list.
	Node* getTail() const;	//Returns position (Pointer) of Tail in linked list.
	//CREATE A SEARCH FUNCTION? IT WILL BE FASTER TBH

private:
	Node* head;
	Node* tail;
	int MAX(int marr[101]);	//Used to find the max value for the mode function (in private because helper function)
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);	//Calls linked list Print() and puts it into the passed in stream.
#endif																//This stream is then returned.
