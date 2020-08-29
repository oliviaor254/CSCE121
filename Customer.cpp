#include <iostream>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int Customer::counter = 0;

Customer::Customer(int customerID, const char name[], bool credit) : id(customerID), balance(0) {
	setName(name);
	setCredit(credit);
	ProdCounter = 0;
}

int Customer::getID() const {
	return id;
}

double Customer::getBalance() const {
	return balance;
}

void Customer::setCredit(bool hasCredit) {
	if (hasCredit) {
		credit = true;
	}
	else {
		credit = false;
	}
}

bool Customer::getCredit() const { return credit; }

void Customer::setName(const char customerName[]) {
	if (strlen(customerName) > 0) {
		strcpy(this->name, customerName);
	}
	else {
		counter++;
		ostringstream oss;
		oss << "Customer " << counter;
		strcpy(this->name, oss.str().c_str());
	}
}

const char* Customer::getName() const { return name; }

bool Customer::processPayment(double amount) {
	if (amount >= 0) {
		balance += amount;
		return true;
	}
	return false;
}

bool Customer::processPurchase(double amount, Product product) {
	if (((!this->credit) && (this->balance < amount)) || (amount < 0)) {
		return false;
	}
	if (ProdCounter >= 5) {
		for (int a = 4; a >= 1; a--) {
			strcpy(productsPurchased[a], productsPurchased[a - 1]);
		}
	}
	else {
		for (int a = ProdCounter; a >= 1; a--)
			strcpy(productsPurchased[a], productsPurchased[a - 1]);
	}
	strcpy(productsPurchased[0], product.getName());
	ProdCounter++;
	balance -= amount;
	return true;
}

void Customer::outputRecentPurchases(std::ostream& os) const {
	os << "Products Purchased ";
	os << "--\n";
	if (ProdCounter == 0) {
		return;
	}
	if (ProdCounter > 5)
		for (int a = 0; a < 5; a++) {
			os << productsPurchased[a] << endl;
		}
	else {
		for (int a = 0; a < ProdCounter; a++) {
			os << productsPurchased[a] << endl;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
	os << "Customer Name: " << customer.getName() << endl;
	os << "Customer ID: " << customer.getID() << endl;
	os << "Has Credit: " << boolalpha << customer.getCredit() << endl;
	os << "Balance: " << customer.getBalance() << endl;
	customer.outputRecentPurchases(os);

	return os;
}