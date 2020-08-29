#ifndef NODE
#define NODE

#include "TemperatureData.h"

struct Node {
	TemperatureData data;
	Node* next;


	Node();	//Default constructor. Calls TemperatureData default constructor as well. Sets 'next' attribute to nullptr
	Node(TemperatureData data);	//The node's data attribute is intialized to the TemperatureData obj parameter, and 'next' is set to nullptr.
	Node(string iD, int yeAr, int mOntH, double TeMp);	//A TemperatureData obj is created based off these parameters and the node's data is set to this created obj.
														//Next is set to nullptr
	bool operator<(const Node& b);		//Compares two nodes to each other based off their values. Calls TemperatureData operator '<' function.
										//Returns true if "this Node" has smaller values than "Node b".

	virtual ~Node() {}
};

#endif
