#pragma once
#include <vector>
#include <iostream>
#include "Book.hpp"

class Favorites
{
private:
	std::vector<Book> favProducts;
	int numProducts;

public:
	Favorites();
	int getNumProducts()const;
	void addToFav(Book);
	void removeFromCart(Book);

	void printFavProducts();

};

