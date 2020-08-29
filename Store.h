#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Customer.h"

class Store {
	char name[100];
	Product* products[100];
	Customer* customers[100];
	static int counter;
	int numProducts;
	int numCustomers;
public:
	Store();	//Creates a store object with its name attribute set to Store <num>

	Store(const char name[]);	//Creates a store object with a name passed in and sets name attribute to parameter name

	const char* getName();	//Returns object's name attribute


	void setName(const char storeName[]);	//Set's object's name attribute to storeName. If "" is passed through parameter, the object's name is set to Store <num>

	bool addProduct(int productID, const char productName[]);	//If Product pointer with the productID passed through parameter is doesn't match another ID in the product pointer array
																// A pointer is created and added to the product pointer array and returns true. False is returned if the ID is already in the pointer array

	Product* getProduct(int productID);	//Get's pointer to the product with ProductID in the pointer product array and returns that pointer

	bool addCustomer(int customerID, const char customerName[], bool credit = false);	//If Customer pointer with the customerID passed through parameter is doesn't match another ID in the customer pointer array
																						// A pointer is created and added to the product pointer array and returns true. False is returned if the ID is already in the pointer array

	Customer* getCustomer(int customerID);	//Get's pointer to the customer with customerID in the pointer customer array and returns that pointer

	bool takeShipment(int productID, int quantity, double cost);	//If quantity of cost is (-) or the product is not in the product pointer array, returns false 
																	//If the product is found in the product pointer array, add shipment is added to that product with the quantity and cost of the product from the parameter and returns true

	bool sellProduct(int customerID, int productID, int quantity);	//Returns false if customer with customerID or product with productID is not in the product/customer pointer array
																	//Or if there is not a negative quantity or not enough inventory of that product, or if the price is (-) or the price is more than the customers balance																
																	//Sells product if nothing returns false beforehand (reduces the inventory from product and calls process purchase for customer) and returns true

	bool takePayment(int customerID, double amount);	//Returns false if amount is negative or customer with that customerID is not in the customer pointer array
														//Otherwise calls process payment for customer with customerID  and returns false

	void outputProducts(std::ostream& os);	//Outputs the list of products in the store's product pointer array to the os stream from the parameter

	void outputCustomers(std::ostream& os);	//Outputs the list of customers in the store's customer pointer array to the os stream from the parameter
};

#endif
