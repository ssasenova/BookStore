#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart() {
	this->cartProducts = std::vector<Book>();
	this->totalCost = 0;
	this->numProducts = 0;
}

int ShoppingCart::getNumProducts() const {
	return this->numProducts;
}

void ShoppingCart::addToCart(Book product) {
	cartProducts.push_back(product);

	this->numProducts++;
	this->totalCost += product.getPrice();
}



void ShoppingCart::removeFromCart(Book product) {
	for (int i = 0; i < this->numProducts; i++)
	{
		if (product.getTitle() == this->cartProducts[i].getTitle()) {
			this->totalCost -= cartProducts[i].getPrice();
			this->numProducts--;
			this->cartProducts.erase(this->cartProducts.begin() + i);
			return;
		}
	}
}

double ShoppingCart::getTotalCost() {
	return this->totalCost;
}

void ShoppingCart::printCartProducts() {
	for (int i = 0; i < this->numProducts; i++)
	{
		cartProducts[i].print();
		std::cout << "\n";
	}
}
