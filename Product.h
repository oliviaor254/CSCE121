#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product {
	int id, inventory, numSold;
	char name[100];
	char description[100];
	double totalPaid;
	static int counter;
public:
	Product(int productID, const char productName[]);	//Creates a Product object with a product ID and Name

	int getID() const;	//Returns value (int) of ID attribute

	const char* getName() const;	//Returns value (char array) of name attribute

	void setName(const char productName[]);	//Sets object's name attribute to productName. If char parameter = "" a default name of "Product <num>" is assigned to object's name

	const char* getDescription() const;	//Returns value (char array) of description attribute	

	void setDescription(const char description[]);	//Sets object's description attribute to description from parameter

	int getNumberSold() const;	//Returns number of the number product sold for that specific object (a running total)

	double getTotalPaid() const;	//Returns double of the amount paid for a shipment of that product

	int getInventoryCount() const;	//Returns value (int) of the object's inventory attribute (added to in addShipment and subtracted from in reduceInventory)

	bool addShipment(int shipmentQuantity, double shipmentCost);	//Returns false if any of the parameters are negative and adds shipmentquantity to the product's inventory attribute and
																	//adds shipmentCost to the product's totalpaid attribute and returns true

	bool reduceInventory(int purchaseQuantity);	//Reduces obj's inventory attribute by amount passed in if amount is (+) and returns true, if amount is (-) false is immediately returned

	double getPrice() const;	//Finds price per product based on inventory and numSold multiplied by a 25% markup
};

std::ostream& operator<<(std::ostream& os, const Product& product);

#endif
