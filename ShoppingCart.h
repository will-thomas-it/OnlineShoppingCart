#ifndef ShoppingCart_H
#define ShoppingCart_H

#include <iostream>
#include <string>
#include <vector>

#include "ItemToPurchase.h"

class ShoppingCart{
	public:
		ShoppingCart();
		ShoppingCart(string customer, string date);
		void SetCustomerName(string customer);
		void SetDate(string date);
		string GetCustomerName() const;
		string GetDate() const;
		void AddItem(ItemToPurchase);
		void RemoveItem(string name);
		void ModifyItem(ItemToPurchase);
		int GetNumItemsInCart() const;
		int GetCostOfCart() const;
		void PrintTotal();
		void PrintDescriptions();
	private:
		string customerName;
		string currentDate;
		vector <ItemToPurchase> cartItems;
};

#endif