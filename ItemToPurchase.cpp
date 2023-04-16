#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase(){
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity){
	itemName = name;
	itemDescription = description;
	itemPrice = price;
	itemQuantity = quantity;

}

void ItemToPurchase::SetName(string name){
	itemName = name;
}

string ItemToPurchase::GetName() const{
	return itemName;
}

void ItemToPurchase::SetPrice(int price){
	itemPrice = price;
}

int ItemToPurchase::GetPrice() const{
	return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const{
	return itemQuantity;
}

void ItemToPurchase::SetDescription(string description){
	itemDescription = description;
}

string ItemToPurchase::GetDescription() const{
	return itemDescription;
}

void ItemToPurchase::PrintItemCost(string name, int quantity, int price, int subtotalPrice){

	cout << name << " " << quantity << " @ $" << price << " = $" << subtotalPrice << endl;
}

void ItemToPurchase::PrintItemDescription(string name, string description){

	cout << name << ": " << description << "." << endl;
}