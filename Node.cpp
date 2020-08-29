#include <string>
#include "Node.h"
#include"TemperatureData.h"
using namespace std;

Node::Node() {
	this->next = nullptr;
	TemperatureData data();
}

Node::Node(TemperatureData data) {
	this->next = nullptr;
	this->data = data;

}
Node::Node(string iD, int yeAr, int mOntH, double TeMp) {
	next = nullptr;
	data = TemperatureData(iD, yeAr, mOntH, TeMp);
}
bool Node::operator<(const Node& b) {
	return (this->data < b.data);
}
