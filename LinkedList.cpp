#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	Node* cur = source.head;
	while (cur != nullptr) {
		Node* newNode = new Node(cur->data);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			tail->next = nullptr;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		cur = cur->next;
	}
}

bool LinkedList::is_empty() const {
	if (head == nullptr && tail == nullptr)
		return true;
	else
		return false;
}

LinkedList& LinkedList::operator=(const LinkedList& replacer) {
	if (replacer.is_empty()) {
		return *this;
	}
	if (this != &replacer) {
		this->clear();
		if (replacer.getHead() == replacer.getTail()) {
			this->head = replacer.getHead();
			this->tail = head->next;
			return *this;
		}
		Node* curr_replacer = replacer.getHead();
		this->head = new Node(curr_replacer->data);
		curr_replacer = curr_replacer->next;
		Node* curr_orig = this->head;
		while (curr_replacer != nullptr) {
			curr_orig->next = new Node(curr_replacer->data);
			this->tail = curr_orig->next;
			curr_replacer = curr_replacer->next;
			curr_orig = curr_orig->next;
		}
	}
	return *this;
}

void LinkedList::insert(string ID, int YR, int MONTH, double TEMP) {
	Node* insertion = new Node(ID, YR, MONTH, TEMP);
	if ((head == nullptr) && (tail == nullptr)) {
		head = insertion;
		tail = insertion;
		return;
	}
	Node* curr = head;
	Node* LookA = curr->next;
	if (insertion->data < this->getHead()->data) {
		insertion->next = this->head;
		this->head = insertion;
		return;
	}
	while (LookA != nullptr) {
		if (insertion->data < LookA->data) {
			curr->next = insertion;
			insertion->next = LookA;
			return;
		}
		curr = LookA;
		LookA = LookA->next;
	}
	this->tail->next = insertion;
	insertion->next = nullptr;
	this->tail = insertion;
}

void LinkedList::clear() {
	Node *Temp = nullptr;
	while (head != nullptr) {
		Temp = head;
		head = head->next;
		delete Temp;
	}
}

Node* LinkedList::getHead() const {
	return this->head;
}

Node* LinkedList::getTail() const {
	return this->tail;
}

string LinkedList::print() const {
	stringstream ss;
	string outputString;
	if (head == nullptr) {
		outputString = "<Empty List>";
	}
	Node* spot = head;
	while (spot != nullptr) {
		ss << spot->data.id << " " << spot->data.year << " " << spot->data.month << " " << spot->data.temperature << '\n';
		spot = spot->next;
	}
	outputString = ss.str();
	return outputString;
}

int LinkedList::MAX(int marr[101]) {
	int ModeI = 0;
	int ModeVal = marr[0];
	for (int a = 0; a < 101; a++) {
		if ((marr[a] >= ModeVal)) {
			ModeVal = marr[a];
			ModeI = a;
		}
	}
	return ModeI;
}

int LinkedList::ModE(int hiR, int loR, string id) {
	int maxIndx = 0;
	int val = 0;
	int ModeTrackr[101] = { };
	int c = 0;
	int M = 0;
	Node* spot = head;
	while (spot != nullptr) {
		if ((spot->data.year >= loR) && (spot->data.year <= hiR) && (spot->data.id == id)) {
			val = int(round(spot->data.temperature + 50));
			ModeTrackr[val] = ModeTrackr[val] + 1;
			c++;
		}
		spot = spot->next;
	}
	if (c == 0) {
		return -60;
	}
	maxIndx = MAX(ModeTrackr);
	M = maxIndx-50;
	return M;
}

double LinkedList::Average(int hiYr, int loYr, string id) {
	double avg = 0;
	int count = 0;
	Node* curr = this->head;
	while (curr != nullptr) { 

		if ((curr->data.year >= loYr) && (curr->data.year <= hiYr) && (curr->data.id == id)) {
			avg += curr->data.temperature;
			count++;
		}
		curr = curr->next;
	}
	if (count == 0) {
		avg = -60;
		return avg;
	}
	avg = avg / count;
	return avg;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}