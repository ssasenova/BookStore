#include <iostream>
#include <string>
#include <vector>
#include "Book.hpp"
#include "ShoppingCart.hpp"
#include "Shop.hpp"

using namespace std;

int main() {
	Shop shop;
	string inputData;

	//user validation
	//created accounts:
	//username:admin19, pass:adminPass
	//username:pesho, pass:pesho123
	while (true) {
		cout << "Press:\n->'L' for login\n->'R' for register\n->'E' for exit\n";
		getline(cin, inputData);
		if (inputData != "L" && inputData != "R" && inputData != "E")
		{
			cout << "Wrong input! Try again!\n";
			continue;
		}

		if (inputData == "R") {
			shop.registerUser();
		}
		if (inputData == "L") {
			shop.userLogin();
		}
		if (inputData == "E") {
			cout << "Goodbye!";
			return 0;
		}
		break;
	}

	string answer;
	if (shop.getCurrUsername() == "admin19") {
		cout << "\n----------Administrator Menu----------";

		while (true) {
			cout << "\n1. Add new book\n2. Remove product\n3. List all users\n4. List all products\n5. Add to quantity of available book\n6. Exit";
			cout << "\nChoose one of above: ";
			getline(cin, answer);
			//if (cin.fail()) {
			//	cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//}

			if (answer == "1") {
				system("CLS");
				cout << "-----Book description-----\n";
				shop.addBook();

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else if (answer == "2") {
				cout << "Product id: ";
				getline(cin, answer);
				int intAnswer = stoi(answer);
				shop.removeProdById(intAnswer);
				continue;
			}
			else if (answer == "3") {
				system("CLS");
				cout << "-----Users-----\n";
				shop.printAllUsers();
				continue;
			}
			else if (answer == "4") {
				system("CLS");
				cout << "-------All books-------\n";
				shop.printAllProducts();
				continue;
			}
			else if (answer == "5") {
				system("CLS");
				cout << "Title of book to adding: ";
				getline(cin, answer);
				cout << "Quantity to add: ";
				int ansInt = 0;
				cin >> ansInt;
				shop.addToQuantity(answer, ansInt);

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			else if (answer == "6") {
				system("CLS");
				cout << "Goodbye!\n";
				return 0;
			}

			cout << "Wrong input! Try again!\n";
		}
	}
	else
	{
		string answerStr;
		cout << "\n----------Welcome to the BookStore----------";
		while (true) {
			cout << "\n1. List all books\n2. Sort products by name\n3. Sort products by price\n4. Add product in shopping cart\n";
			cout << "5. Add product to favorites\n6. View shopping cart products\n7. View favorite products\n8. View total cost of shopping cart products\n9. Exit";
			cout << "\nChoose one of above: ";
			getline(cin, answer);

			if (answer == "1") {
				system("CLS");
				cout << "--------All books--------\n";
				shop.printAllProducts();
			}
			else if (answer == "2") {
				system("CLS");
				shop.sortByTitle();
			}
			else if (answer == "3") {
				while (true) {
					cout << "\n1. Ascending order\n2. Descending order\nChoose one of above: ";
					getline(cin, answer);
					if (answer == "1") {
						system("CLS");
						shop.sortByPriceASC();
						break;
					}
					else if (answer == "2") {
						system("CLS");
						shop.sortByPriceDSC();
						break;
					}
					else
						cout << "\nWrong input! Try again!\n";
				}
			}
			else if (answer == "4") {
				system("CLS");
				cout << "Title of wanted book is: ";
				getline(cin, answer);
				shop.addToCartByTitle(answer);
			}
			else if (answer == "5") {
				system("CLS");
				cout << "Title of wanted book is: ";
				getline(cin, answer);
				shop.addToFavByTitle(answer);
			}
			else if (answer == "6") {
				system("CLS");
				cout << "-----Shopping cart products-----\n";
				shop.listCartProducts();
			}
			else if (answer == "7") {
				system("CLS");
				cout << "-----Favorite products-----\n";
				shop.listFavProducts();
			}
			else if (answer == "8") {
				system("CLS");
				cout << "Total cost: ";
				printf("%.2lf", shop.getTotalCost());
				cout << "lv.\n";
			}
			else if (answer == "9") {
				system("CLS");
				cout << "Goodbye!\n";
				return 0;
			}
			else
				cout << "Wrong input! Try again!\n";

		}
	}

	return 0;
}