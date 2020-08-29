#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "Product.h"

class Customer {
	int id;
	char name[100];
	bool credit;
	double balance;
	char productsPurchased[5][100];
	int numPurchased;
	static int counter;
	int ProdCounter;
public:
	Customer(int customerID, const char name[], bool credit = false);//Creates a Customer object with ID, name , and a Credit Attribute

	int getID() const;	//Returns value (int) of that object's ID attribute 

	const char* getName() const;	//Returns value (char array) of object's name attribute

	void setName(char const customerName[]);	//Sets object's name attribute to customreName. If char parameter = "" a default name of "Customer <num>" is assigned to object's name

	bool getCredit() const;	//Returns value (bool) of object's credit attribute

	void setCredit(bool hasCredit);	//Sets object's credit attribute to value of hasCredit

	double getBalance() const;	//Returns value (double) of object's balance attribute

	bool processPayment(double amount);	//Adds value of parameter (double) to the object's balance attribute and returns true. Returns false if amount is (-) and amount is not added to balance

	bool processPurchase(double amount, Product product);	//Adds product name to productsPurchased array (at index 0). If amount is (+) and smaller than the object's balance or the object's credit attribute is
															//true. If ProdCounter is >5, the last element in productsPurchased is eliminated, and every element shifts up one index returns false if any of these conditions
															//aren't met. If credit is false, balance has to be greater than amount in order to return true and add product to productsPurchased array

	void outputRecentPurchases(std::ostream& os) const;	//Outputs the names of the products in products purchased array to ostream passed in
};

std::ostream& operator<<(std::ostream& os, const Customer& customer);

#endif
