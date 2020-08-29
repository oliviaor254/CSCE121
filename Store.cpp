#include <iostream>
#include <sstream>
#include "Store.h"
#include "Product.h"
#include "Customer.h"
using namespace std;

int Store::counter = 0;

Store::Store() {
	setName(name);
	numCustomers = 0;
	numProducts = 0;
}

Store::Store(const char name[]) {
	setName(name);
	numCustomers = 0;
	numProducts = 0;
}

const char* Store::getName() {
	return name;
}

void Store::setName(const char storeName[]) {
	if (strlen(storeName) > 0) {
		strcpy(this->name, storeName);
	}
	else {
		counter++;
		ostringstream oss;
		oss << "Store " << counter;
		strcpy(this->name, oss.str().c_str());
	}
}

bool Store::addProduct(int productID, const char productName[]) {
	for (int i = 0; i < numProducts; i++) {
		if (products[i]->getID() == productID)
			return false;
	}
	Product* p = new Product(productID, productName);
	products[numProducts] = p;
	numProducts++;
	return true;
}

Product* Store::getProduct(int productID) {
	bool match = false;
	for (int j = 0; j < numProducts; j++) {
		if (products[j]->getID() == productID) {
			match = true;
			return products[j];
		}
	}
	if (!match) {
		return nullptr;
	}
}

bool Store::addCustomer(int customerID, const char customerName[], bool credit) {
	for (int i = 0; i < numCustomers; i++) {
		if (customers[i]->getID() == customerID) {
			return false;
		}
	}
	Customer* c = new Customer(customerID, customerName, credit);
	customers[numCustomers] = c;
	numCustomers++;
	return true;
}

Customer* Store::getCustomer(int CustomerID) {
	bool match = false;
	for (int j = 0; j < numCustomers; j++) {
		if (customers[j]->getID() == CustomerID) {
			match = true;
			return customers[j];
		}
	}
	if (!match) {
		return nullptr;
	}
}

bool Store::takeShipment(int productID, int quantity, double cost) {
	if ((quantity < 0) || (cost < 0)) {
		return false;
	}
	for (int j = 0; j < numProducts; j++) {
		if (products[j]->getID() == productID) {
			products[j]->addShipment(quantity, cost);
			return true;
		}
	}
	return false;
}

bool Store::sellProduct(int customerID, int productID, int quantity) {
	double price = 0.0;
	Product* TempProd = getProduct(productID);
	Customer* TempCust = getCustomer(customerID);
	if ((TempCust == nullptr) || (TempProd == nullptr) || (quantity < 0) || (TempProd->getInventoryCount() < quantity)) {
		return false;
	}
	price = TempProd->getPrice() * quantity;
	if (((!TempCust->getCredit()) && (TempCust->getBalance() < price)) || (price < 0)) {
		return false;
	}
	TempProd->reduceInventory(quantity);
	TempCust->processPurchase(price, (*TempProd));
	return true;
}

bool Store::takePayment(int customerID, double amount) {
	if (amount < 0) {
		return false;
	}
	Customer* Buyer = getCustomer(customerID);
	if (Buyer == nullptr) {
		return false;
	}
	Buyer->processPayment(amount);
	return true;
}

void Store::outputProducts(std::ostream& os) {
	for (int item = 0; item < numProducts; item++) {
		os << (*products[item]) << endl;
	}
}

void Store::outputCustomers(std::ostream& os) {
	for (int persons = 0; persons < numCustomers; persons++) {
		os << (*customers[persons]) << endl;
	}
}