/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */
#include <string>
#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0.0) {}

TemperatureData::TemperatureData(string Id, int Year, int Month, double Temperature) : id(Id), year(Year), month(Month), temperature(Temperature) {} //initialize everything

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
	if (this->id < b.id) {
		return true;
	}
	else if ((this->id == b.id) && (this->year < b.year)) {
		return true;
	}
	else if (((this->id == b.id) && (this->year == b.year)) && (this->month < b.month)) {
		return true;
	}
	return false;
}



