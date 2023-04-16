#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart(){
	customerName = "none";
	currentDate = "January 1, 2016";
	vector <ItemToPurchase> cartItems;
}

ShoppingCart::ShoppingCart(string customer, string date){
	customerName = customer;
	currentDate = date;
}

void ShoppingCart::SetCustomerName(string customer){
	customerName = customer;
}

void ShoppingCart::SetDate(string date){
	currentDate = date;
}

string ShoppingCart::GetCustomerName() const{
	return customerName;
}

string ShoppingCart::GetDate() const{
	return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase object){
	string nameItem, itemDescription;
	int priceItem, quantityItem;


	cout << "ADD ITEM TO CART" << endl;
	cin.ignore();
	cout << "Enter the item name:" << endl;
	getline(cin, nameItem);

	cout << "Enter the item description:" << endl;
	getline(cin, itemDescription);

	cout << "Enter the item price:" << endl;
	cin >> priceItem;

	cout << "Enter the item quantity:" << endl;
	cin >> quantityItem;
	cout << endl;

	object.SetName(nameItem);
	object.SetDescription(itemDescription);
	object.SetPrice(priceItem);
	object.SetQuantity(quantityItem);

	object.GetName();
	object.GetDescription();
	object.GetPrice();
	object.GetQuantity();


	cartItems.push_back(object);

}

void ShoppingCart:: RemoveItem(string name){
	ItemToPurchase createObjectForOperator;
	unsigned int oldSize = cartItems.size();

	cout << "REMOVE ITEM FROM CART" << endl;
    cin.ignore();
    cout << "Enter name of item to remove:" << endl;
    getline(cin, name);

	for ( unsigned int i = 0; i < cartItems.size(); ++i){
		createObjectForOperator = cartItems.at(i);
		if (createObjectForOperator.GetName() == name){
			cartItems.erase(cartItems.begin() + i);
		}

    }
    if (oldSize == cartItems.size()){
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase object){
	string nameItem;
	int newQuantity;
	bool checkItem = false;

	cout << "CHANGE ITEM QUANTITY" << endl;
	cin.ignore();
	cout << "Enter the item name:" << endl;
	getline(cin, nameItem);
	cout << "Enter the new quantity:" << endl;
    cin >> newQuantity;

        for (unsigned int i = 0; i < cartItems.size(); ++i){
		object = cartItems.at(i);
            if (cartItems.at(i).GetName() == nameItem){
                //if the object does not have default values for description, price, and quantity, then modify
                if (object.GetQuantity() != 0 && object.GetPrice() != 0 && object.GetDescription() != "none"){
                    cartItems.erase(cartItems.begin() + i);
                    object.SetQuantity(newQuantity);
                    cartItems.insert(cartItems.begin(), object);
                }
                checkItem = true;
            }

        }
        if (checkItem == false){
                cout << "Item not found in cart. Nothing modified." << endl;
            }
}

int ShoppingCart:: GetNumItemsInCart() const{
	int counting = 0;
	ItemToPurchase createObjectForOperator;

	for (unsigned int i = 0; i < cartItems.size(); ++i){
		createObjectForOperator = cartItems.at(i);

		counting += createObjectForOperator.GetQuantity(); 
	}

	return counting;
}


int ShoppingCart:: GetCostOfCart() const{
	ItemToPurchase accessMember;
	int totalCost = 0;
	for (unsigned int i = 0; i < cartItems.size(); ++i){
		accessMember = cartItems.at(i);
		totalCost += accessMember.GetPrice() * accessMember.GetQuantity();

	}

	return totalCost;
}


void ShoppingCart::PrintTotal(){

	ShoppingCart classobjects;
	ItemToPurchase object;

	if (cartItems.size() == 0){
             cout << "SHOPPING CART IS EMPTY" << endl;
	}
	else{
        for (unsigned int i = 0; i < cartItems.size(); ++i){
            object = cartItems.at(i);
            cout << object.GetName() << " " <<  object.GetQuantity() << " @ $" << object.GetPrice() << " = $" << object.GetPrice() * object.GetQuantity() << endl;

        }
	}
}

void ShoppingCart::PrintDescriptions(){
	ShoppingCart classobjects;
	ItemToPurchase object;

	cout << "Item Descriptions" << endl;
	for (unsigned int i = 0; i < cartItems.size(); ++i){
            object = cartItems.at(i);
		cout << object.GetName() <<": "<< object.GetDescription() << endl;
	}

}