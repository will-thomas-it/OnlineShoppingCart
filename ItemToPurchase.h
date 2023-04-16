#ifndef ItemToPurchase_H
#define ItemToPurchase_H

#include <iostream>
#include <string>

using namespace std;

class ItemToPurchase{
	public:
		ItemToPurchase();
		ItemToPurchase(string name, string description, int price, int quantity);
		
		void SetName(string name);
		string GetName() const;

		void SetPrice(int price);
		int GetPrice() const;

		void SetQuantity(int quantity);
		int GetQuantity() const;

		void SetDescription(string description);
		string GetDescription() const;

		void PrintItemCost(string name, int quantity, int price, int subtotalPrice);
		void PrintItemDescription(string name, string description);

	private:
		string itemName;
		string itemDescription;
		int itemPrice;
		int itemQuantity;

};

#endif