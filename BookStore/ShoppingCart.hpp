#pragma once
#include "Book.hpp"
#include <vector>
#include <iostream>

class ShoppingCart
{
private:
	std::vector<Book> cartProducts;
	int numProducts;
	double totalCost;

public:
	ShoppingCart();

	int getNumProducts()const;
	void addToCart(Book);
	void removeFromCart(Book);
	double getTotalCost();

	void printCartProducts();
};

