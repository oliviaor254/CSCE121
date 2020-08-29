#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "LinkedList.h"

class TemperatureDatabase {
public:
	TemperatureDatabase();	//Default constructor. Calls TemperatureData default constructor as well;
	~TemperatureDatabase();	//Destructor

	void loadData(const std::string& data_file);	//Loads a linked list of records in ascending order based off Id, year and/or month

	// Read the queries from the query file and perform a series of queries
	void performQuery(const std::string& query_filename);	//Reads queries from a file and returns a file with the answers to those queries

private:
	LinkedList records;
	const int MaxYear = 2019;

};

#endif  // TEMP_DB
