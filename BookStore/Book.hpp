#pragma once
#include <string>

class Book
{
private:
	std::string title;
	int pages;
	std::string genre;
	std::string author;
	double price;
	int quantity;
	int id;

	void copyData(const Book&);

public:
	void setPages(const int&);
	int getPages()const;
	void setGenre(const std::string&);
	std::string getGenre()const;
	void setAuthor(const std::string&);
	std::string getAuthor()const;
	void setTitle(const std::string&);
	std::string getTitle()const;
	void setPrice(const double&);
	double getPrice()const;
	void setQuantity(int);
	int getQuantity()const;
	void setId(const int&);
	int getId()const;
	void addToQuantity(const int&);
	void quantityChange();

	Book();
	Book(const Book& other);
	Book& operator=(const Book& other);
	Book(const std::string& title, const std::string& author, const std::string& genre, int pages, double price, int quantity, int id);

	void print();
};

