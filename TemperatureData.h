/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
using namespace std;
struct TemperatureData {
	string id;
	int year;
	int month;
	double temperature;
	TemperatureData();	//Default constructor. Initializes all attributes of TemperatureData to 0 or "".
	TemperatureData(string Id, int Year, int Month, double Temperature);	//Creates a new struct TemperatureData based off the parameters.
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);	//Compares the attributes of the passed in object and "this object".
};												//Returns true if "this id" is less than "id", if these are equal, compares the values of
												//"this year" or "this month" is less than the passed in month or year. Returns false if not.
#endif /* TEMPERATUREDATA */
