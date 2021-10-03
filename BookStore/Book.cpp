#pragma warning(disable: 4996)
#include <string>
#include <iostream>
#include "Book.hpp"

using namespace std;

void Book::setGenre(const string& genre)
{
	this->genre = genre;
}
string Book::getGenre()const
{
	return this->genre;
}
void Book::setAuthor(const string& author)
{
	this->author = author;
}
string Book::getAuthor()const
{
	return this->author;
}
void Book::setPages(const int& count)
{
	this->pages = count;
}
int Book::getPages()const
{
	return this->pages;
}
void Book::setTitle(const std::string& title) {
	this->title = title;
}

std::string Book::getTitle() const {
	return this->title;
}

void Book::setPrice(const double& price) {
	this->price = price;
}

double Book::getPrice()const {
	return this->price;
}

void Book::setQuantity(int quantity) {
	this->quantity = quantity;
}

int Book::getQuantity() const {
	return this->quantity;
}

void Book::setId(const int& id) {
	this->id = id;
}

int Book::getId() const {
	return this->id;
}

void Book::addToQuantity(const int& numProducts) {
	this->quantity += numProducts;
}

void Book::quantityChange()
{
	int newQuantity = this->quantity - 1;
	setQuantity(newQuantity);
}

void Book::copyData(const Book& other)
{
	this->author = other.author;
	this->genre = other.genre;
	this->pages = other.pages;
	this->title = other.title;
	this->price = other.price;
	this->quantity = other.quantity;
	this->id = other.id;
}

Book::Book()
{
	this->author = "";
	this->genre = "";
	this->pages = 0;
}

Book::Book(const std::string& title, const std::string& author, const std::string& genre, int pages, double price, int quantity, int id) {

	this->author = author;
	this->genre = genre;
	this->pages = pages;
	this->title = title;
	this->price = price;
	this->quantity = quantity;
	this->id = id;
}

Book::Book(const Book& other)
{
	copyData(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		copyData(other);
	}
	return *this;
}

void Book::print()
{
	cout << "Title: " << this->title << endl;
	cout << "Author: " << this->author << endl;
	cout << "Genre: " << this->genre << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Price: ";
	printf("%.2lf", this->price);
	cout << "lv.\n";
	cout << "Quantity: " << this->quantity << endl;
}
