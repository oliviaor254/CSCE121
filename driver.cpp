#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Store.h"

using namespace std;

int main() {
	/* Product p(17, "Jill");
	 cout << "p (id): " << p.getID() << endl;
	 cout << "p (name): " << p.getName() << endl << endl;

	 Product q(183, "Tom");
	 cout << "q (id): " << q.getID() << endl;
	 cout << "q (name): " << q.getName() << endl << endl;

	 Product badP(222, "");
	 cout << "badP (id): " << badP.getID() << endl;
	 cout << "badP (name): " << badP.getName() << endl << endl;

	 p.setName("Jill Extreme");
	 cout << "p (name): " << p.getName() << endl;

	 q.setName("");
	 cout << "q (name): " << q.getName() << endl;

	 p.setDescription("This is a fantastic product.");
	 cout << "p (description): " << p.getDescription() << endl;

	 q.setDescription("");
	 cout << "q (description): " << q.getDescription() << endl << endl;

	 cout << "Before 1st shipment" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;	//-1 correct?
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 p.addShipment(88, 230.44);

	 cout << "After 1st shipment" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 p.addShipment(133, 142.11);

	 cout << "After 2nd shipment" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 cout << "Testing negative quantity" << endl;

	 if (!p.addShipment(-5, 22.55)) {
		 cout << "shipment failed" << endl;
	 }
	 else {
		 cout << "shipment passed" << endl;
	 }

	 cout << "After failed shipment (nothing should change from last output)" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;


	 cout << "Testing negative shipment cost" << endl;

	 if (!p.addShipment(5, -22.55)) {
		 cout << "shipment failed" << endl;
	 }
	 else {
		 cout << "shipment passed" << endl;
	 }

	 cout << "After failed shipment (nothing should change from last output)" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 cout << "Testing reduceInventory" << endl;

	 p.reduceInventory(33);

	 cout << "After reduceInventory" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 cout << "Testing reduceInventory (negative quantity)" << endl;
	 if (!p.reduceInventory(-75)) {
		 cout << "reduction failed" << endl;
	 }
	 else {
		 cout << "reduction passed" << endl;
	 }

	 cout << "After failed reduceInventory (nothing should change from last output)" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;

	 cout << "Testing reduceInventory (more than inventory)" << endl;
	 if (!p.reduceInventory(500)) {
		 cout << "reduction failed" << endl;
	 }
	 else {
		 cout << "reduction passed" << endl;
	 }

	 cout << "After failed reduceInventory (nothing should change from last output)" << endl;
	 cout << "inventory: " << p.getInventoryCount() << endl;
	 cout << "totalPaid: " << p.getTotalPaid() << endl;
	 cout << "price: " << p.getPrice() << endl;
	 cout << "numSold: " << p.getNumberSold() << endl << endl;*/
	Product coozi(32498, "Coozie");		//Follow this model
	coozi.setDescription("A great way to keep a canned beverage cold.");
	coozi.addShipment(100, 103.75);
	coozi.reduceInventory(17);
	cout << coozi;
	Product o(123, "Opal");
	o.setDescription("This does some fun stuff.");
	cout << "--------------------------------------------------------" << endl;

	Customer missRev(2198123, "Miss Reveille", true);
	cout << missRev;

	/*cout << "Customer Class Testing" << endl;		//CLEAN UP DRIVER ORGANIZATION

	Customer c1(872, "Carol", true);

	//cout << "c1(ID): " << c1;

	Customer nn(65, "", true);

	cout << "nn(ID): " << nn.getID() << endl;
	cout << "nn(Name): " << nn.getName() << endl;
	cout << "nn(Credit): " << boolalpha << nn.getCredit() << endl << endl;

	Customer lng(65, "Bladyughfoulmoeck");*/

	/*cout << "lng(ID): " << lng.getID() << endl;
	cout << "lng(Name): " << lng.getName() << endl;
	cout << "lng(Credit): " << boolalpha << lng.getCredit() << endl << endl;*/
	/*cout << "c1(Balance): " << c1.getBalance() << endl << endl;

	c1.setCredit(false);

	cout << "c1(ChangedCredit): " << c1.getCredit() << endl << endl;

	cout << "c1 (New balance): " << c1.getBalance() << endl;
	cout << "lng ProcessPay: " << boolalpha << lng.processPayment(-38) << endl;
	cout << "lng (new Balance): " << lng.getBalance() << endl << endl;

	Product cooz(1234, "Coozie");
	Product t(345, "Towel");
	
	cout << "c1ProcessPayment(Should be true): " << c1.processPayment(25) << endl;
	cout << "c1 not enough $$: " << boolalpha << c1.processPurchase(35, cooz) << endl;
	cout << "c1 cur balance: " << c1.getBalance() << endl;

	c1.processPurchase(3, t);
	cout << "Bought a towel "<< c1.getBalance();
	cout << endl;
	c1.outputRecentPurchases(cout);
	cout <<"\n nn Process: " << nn.processPurchase(-235, cooz) << endl;
	cout << "nn newBal (SHOULD NOT CHANGE): " << nn.getBalance() << endl << endl;

	cout << "nn Payment: " << nn.processPayment(50) << endl;

	cout << "nnBalance: " << nn.getBalance() << endl;
	cout << "nn Positive purchase: " << boolalpha << nn.processPurchase(35, cooz) << endl;
	cout << "Current Balance: " << nn.getBalance() << endl;
	cout << "nn Not enough in balance: (But true credit) " << boolalpha << nn.processPurchase(80, t) << endl << endl;
	nn.processPurchase(2, o);
	nn.processPurchase(1, cooz);
	cout << "nn Current Balance: " << nn.getBalance() << endl;
	cout << "recent Purchases {nn}: " << endl;
		nn.outputRecentPurchases(cout);
		cout << endl;*/

	cout << "-----------------------" << endl;

	cout << "Store Class Testing" << endl;
	Store Em("Emily's");
	cout << "Emily's Store adding a product: ";
	Em.addProduct(56, "Towel");
	cout << boolalpha << Em.addProduct(56, "Towel") << endl;
	Em.addProduct(87, "Coozie");
	cout << "Getting a product: " << Em.getProduct(87)->getName() << endl;
	cout << "Getting a product(Not in inventory): ";
	if (Em.getProduct(120) == nullptr)
		cout << "--\n";
	cout << "Testing Customers in Store:\n";
	Em.addCustomer(75, "Bowie", true);
	Em.addCustomer(25, "Cheryl");
	Em.addCustomer(67, "Mercury", true);
	cout << "75 name: " << Em.getCustomer(75)->getName() << endl;
	cout << "75 Balance:" <<Em.getCustomer(75)->getBalance() << endl;
	cout << boolalpha << Em.sellProduct(75, 56, 2) << endl;
	cout << "75 add Payment" << boolalpha << Em.getCustomer(75)->processPayment(300) << endl;
	cout << "New Balance" << boolalpha << Em.getCustomer(75)->getBalance() << endl;
	Em.getProduct(56)->addShipment(100, 104.50);
	cout << "INVENTORY OF TOWEL" << Em.getProduct(56)->getInventoryCount() << endl;
	cout << "75 buying product" << boolalpha << Em.sellProduct(75, 56, 2) << endl;
	
	system("pause");
	return 0;
}