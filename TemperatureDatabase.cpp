#include <cstring>
#include <fstream>
#include <sstream>
#include "TemperatureDatabase.h"
#include "LinkedList.h"
using namespace std;

TemperatureDatabase::TemperatureDatabase() { LinkedList records(); }
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	string fileid;
	int fileYr, fileMo;
	double fileTemp;
	ifstream inputfile(filename);
	if (!inputfile.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(0);
	}
	else {
		while (!inputfile.eof()) {
			stringstream test;
			string curline;
			getline(inputfile, curline);
			test << curline;
			if (curline.length() < 2) {
				continue;
			}
			test >> fileid;
			test >> fileYr;
			test >> fileMo;
			test >> fileTemp;
			if (test.fail()) {
				cout << "Error: Other invalid input" << endl;
				continue;
			}
			if ((fileYr < 1800) || (fileYr >= MaxYear)) {
				cout << "Error: Invalid year " << fileYr << endl;
				continue;
			}
			if ((fileMo <= 0) || (fileMo > 12)) {
				cout << "Error: Invalid month " << fileMo << endl;
				continue;
			}
			if (fileTemp == -99.99) {
				continue;
			}
			else if ((fileTemp < -50) || (fileTemp > 50)) {
				cout << "Error: Invalid temperature " << fileTemp << endl;
				continue;
			}
			else
			{
				records.insert(fileid, fileYr, fileMo, fileTemp);
			}
		}
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	double mean = 0.0;
	int mode = 0;
	int startYr = 0;
	int endYr = 0;
	string type = "";
	string fileidQ = "";
	stringstream out;
	ifstream filequery(filename);
	if (!filequery.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		return;
	}

	while (!filequery.eof()) {
		stringstream tester;
		string curln;
		getline(filequery, curln);
		tester << curln;
		if (curln.length() < 2) {
			continue;
		}
		tester >> fileidQ;
		tester >> type;
		tester >> startYr;
		tester >> endYr;

		if (tester.fail()) {
			cout << "Error: Other invalid query" << endl;
			continue;
		}
		if (type != "AVG" && type != "MODE") {
			cout << "Error: Unsupported query " << type << endl;
			continue;
		}
		if ((startYr < 1800) || (endYr >= MaxYear) || (startYr > endYr)) {
			cout << "Error: Invalid range " << startYr << "-" << endYr << endl;
			continue;
		}

		if (type == "AVG") {
			mean = records.Average(endYr, startYr, fileidQ);
			if (mean == -60.0)
			{
				out << fileidQ << " " << startYr << " " << endYr << " " << type << " unknown" << endl;
			}
			else {
				out << fileidQ << " " << startYr << " " << endYr << " " << type << " " << mean << endl;
			}
		}
		if (type == "MODE") {
			mode = records.ModE(endYr, startYr, fileidQ);
			if (mode == -60) {
				out << fileidQ << " " << startYr << " " << endYr << " " << type << " unknown" << endl;
			}
			else {
				out << fileidQ << " " << startYr << " " << endYr << " " << type << " " << mode << endl;
			}
		}
	}


	ofstream outfile("result.dat");
	if (!outfile.is_open()) {
		cout << "File could not be opened";
	}
	else {
		outfile << out.str();
	}
}
