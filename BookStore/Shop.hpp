#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Book.hpp"
#include "Login.hpp"
#include "Favorites.hpp"
#include "ShoppingCart.hpp"

class Shop
{
private:
	std::vector<Book> products;
	ShoppingCart shoppingCart;
	Favorites favorites;
	std::vector<Login> users;
	Login currUser;

public:
	Shop();

	std::string getCurrUsername()const;
	std::string getCurrPassword()const;
	void fillInitialInfo();
	void registerUser();
	void addUser(Login);
	void addBook();
	void userLogin();
	void addProduct(Book&);

	void sortByTitle();
	void sortByPriceASC();
	void sortByPriceDSC();

	void addToQuantity(std::string title, int quantityToAdd);

	void addToCartByTitle(std::string);
	void addToFavByTitle(std::string);

	void listCartProducts();
	void listFavProducts();

	double getTotalCost();

	void removeProdById(int id);

	void printAllUsers();
	void printAllProducts();
};

