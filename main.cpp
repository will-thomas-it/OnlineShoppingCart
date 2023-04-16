#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


#include "ItemToPurchase.h"
#include "ShoppingCart.h"


void PrintMenu(ShoppingCart& obj) {
    char userPrompt;

	cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
    "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
    cout << endl;

	do{
		cout << "Choose an option:" << endl;
		cin >> userPrompt;

		switch(userPrompt){
			case 'a':
			{
				ItemToPurchase objectOfPurchase;
				obj.AddItem(objectOfPurchase);
				cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
                "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
                cout << endl;
			}

			break;

			case 'd': 
			{
				string nameItem;
				obj.RemoveItem(nameItem);
				cout << endl;
				cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
                "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
                cout << endl;
			}

			break;

			case 'c':
			{
				ItemToPurchase forChangingQuantity;
				obj.ModifyItem(forChangingQuantity);
				cout << endl;
				cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
                "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
                cout << endl;
			}

			break;

			case 'i':
			{
				cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
				cout << obj.GetCustomerName() << "'s Shopping Cart - " << obj.GetDate() << endl;
				cout << endl;
				obj.PrintDescriptions();
				cout << endl;
				cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
                "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
                cout << endl;
			}
			break;

			case 'o':
			{
			    cout << "OUTPUT SHOPPING CART" << endl;
				cout << obj.GetCustomerName() << "'s Shopping Cart - " << obj.GetDate() << endl;
				cout << "Number of Items: " << obj.GetNumItemsInCart() << endl;
				cout << endl;
				obj.PrintTotal();
				cout << endl;

				cout << "Total: $" << obj.GetCostOfCart() << endl;
				cout << endl;
				cout << "MENU\n" << "a - Add item to cart\n" << "d - Remove item from cart\n" << "c - Change item quantity\n" <<
                "i - Output items' descriptions\n" << "o - Output shopping cart\n" << "q - Quit\n";
                cout << endl;
			}
			break;

			case 'q':
			{
				exit(0);
			}
            break;

            default:
            {
				cin >> userPrompt;
            }
            break;
		}

	}
	while(userPrompt!= 'q');

}

int main(){

	string nameOfCustomer, todayDate;
	ShoppingCart object;

	cout << "Enter customer's name:" << endl;
	getline(cin, nameOfCustomer);

	cout << "Enter today's date:" << endl;
	getline(cin, todayDate);
	cout << endl;


	object.SetCustomerName(nameOfCustomer);
	object.SetDate(todayDate);

	cout << "Customer name: " << object.GetCustomerName() << endl;
	cout << "Today's date: " << object.GetDate() << endl << endl;

	PrintMenu(object);

	return 0;
}