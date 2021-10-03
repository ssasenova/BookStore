#include "Favorites.hpp"

Favorites::Favorites() {
	this->favProducts = std::vector<Book>();
	this->numProducts = 0;
}

int Favorites::getNumProducts() const {
	return this->numProducts;
}

void Favorites::addToFav(Book product) {
	this->favProducts.push_back(product);
	this->numProducts++;
}

void Favorites::removeFromCart(Book product) {
	for (int i = 0; i < this->numProducts; i++) {
		if (product.getTitle() == this->favProducts[i].getTitle()) {
			this->favProducts.erase(this->favProducts.begin() + i);
			this->numProducts--;
		}
	}
}

void Favorites::printFavProducts() {
	for (int i = 0; i < this->numProducts; i++) {
		this->favProducts[i].print();
		std::cout << "\n";
	}
}
