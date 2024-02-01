#include <iostream>
#include <vector>
#include <string>  
#include <limits>
#include <memory>

using namespace std;
// Define Functions

void Menu();
void AddProduct();
void DisplayInventory();
void SellProduct();

// Define global variables 
unique_ptr<vector<string>> Names{ make_unique<vector<string>>() };
unique_ptr<vector<double>> Prices{ make_unique<vector<double>>() };
unique_ptr<vector<  int >> Quantity{ make_unique<vector<int>>() };
static int product_count{ 0 };
string name;
double price;
int quantity;
int sell_quantity;
int product_ID;



int main()
{
	Menu();

	return 0;
}

void Menu()
{

	int userOption = -1;

	while (userOption != 0) {
		cout << "1. Add Product\n";
		cout << "2. Display Inventory\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> userOption;

		// clear input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to prevent at buffer confusion with previous inputs

		// Select your choice
		switch (userOption) {
		case 1:
			AddProduct();
			break;
		case 2:
			DisplayInventory();
			break;
	
		case 3:
			SellProduct();
			break;

		case 0:
			std::cout << "Exiting the program." << std::endl;
			break;
		default:
			std::cout << "Invalid option. Please try again." << std::endl;
		}
	}
}


void AddProduct()
{
	// Enter Name 
	cout << "Enter Product Name" << endl;
	cin >> name;
	Names->push_back(name);

	// Clear the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Enter Price 
	cout << "Enter Product Price: $" << endl;
	cin >> price;
	Prices->push_back(price);

	// Clear the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Enter Quantity 
	cout << "Enter Product Quantity: " << endl;
	cin >> quantity;
	Quantity->push_back(quantity);

	// Clear the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl;
	// Output Product Information
	if (!Names->empty()) {
		std::cout << "Product Name: " << (*Names)[product_count] << std::endl;
	}
	cout << "Product Price: " << Prices->at(product_count) << "$" << endl;
	cout << "Product Quantity: " << Quantity->at(product_count) << endl;
	// we increased our counter for adding new products 
	product_count++;
}


void DisplayInventory()
{
	// if there is no element then our container is empty 
	if (product_count == 0) {
		cout << "Inventory is empty." << endl;
		return;
	}

	cout << "ID \t\t" << "Name \t\t" << "Price \t\t" << "Quantity \t\t" << endl;
	cout << "---------------------------------------------------------" << endl;

	for (int i = 0; i < product_count; i++)
	{
		cout << i+1 << "." << "\t\t" << Names->at(i) << "\t\t" << Prices->at(i) << "\t\t" << Quantity->at(i) << endl;
	}

	cout << "---------------------------------------------------------" << endl;
}

void SellProduct()
{
	if (product_count == 0)
	{
		cout << "There is no product to sell " << endl;
	}
	if (product_count > 0)
	{
		cout << "Enter ID of the product to sell: " << "0" << "-" << product_count-1 << endl;
		cin >> product_ID;
		cout << "Enter quantity of to sell" << endl;
		cin >> sell_quantity;
		cout << endl;
		// uptade remain products
		Quantity->at(product_ID) -= sell_quantity;
	}
	// clear input buffer 
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

}