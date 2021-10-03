#include "Shop.hpp"

Shop::Shop() {

	this->products = std::vector<Book>();
	this->users = std::vector<Login>();
	fillInitialInfo();
}

std::string Shop::getCurrUsername() const
{
	return this->currUser.getUsername();
}

std::string Shop::getCurrPassword() const
{
	return this->currUser.getPassword();
}

void Shop::fillInitialInfo() {
	Book book1("Looking for Alaska", "John Green", "Novel", 297, 15.50, 1, 1001);
	Book book2("The lost symbol", "Dan Brown", "Novel", 327, 19.00, 20, 1002);
	Book book3("The institute", "Stephen King", "Novel", 450, 25.99, 8, 1003);
	Book book4("The Hobbit", "J.R.R. Tolkien", "Novel", 300, 21.00, 4, 1004);
	Book book5("The great Gatsby", "F. Scott Fitzgerald", "Novel", 180, 17.00, 30, 1005);
	Book book6("The Lord of the rings", "J.R.R. Tolkien", "Novel", 1216, 32.99, 22, 1006);
	Book book7("War and peace", "Leo Tolstoy", "Novel", 1296, 40, 50, 1007);
	Book book8("Our souls at night", "Kent Haruf", "Novel", 192, 18.49, 70, 1008);
	Book book9("Angels & demons", "Dan Brown", "Novel", 736, 33.50, 2, 1009);

	this->products.push_back(book1);
	this->products.push_back(book2);
	this->products.push_back(book3);
	this->products.push_back(book4);
	this->products.push_back(book5);
	this->products.push_back(book6);
	this->products.push_back(book7);
	this->products.push_back(book8);
	this->products.push_back(book9);

	Login admin("admin19", "adminPass");
	users.push_back(admin);
	Login user("pesho", "pesho123");
	users.push_back(user);

}


void Shop::registerUser() {

	std::cout << "-----Registration-----\n";
	std::string username;
	std::string password;
	std::string repeatedPassword;
	while (true) {
		std::cout << "Username: ";
		std::getline(std::cin, username);
		std::cout << "Password: ";
		std::getline(std::cin, password);
		std::cout << "Reenter password: ";
		std::getline(std::cin, repeatedPassword);

		if (password == repeatedPassword)
		{
			std::cout << "Successful registration!\n";
			Login newUser(username, password);
			currUser.setUsername(username);
			currUser.setPassword(password);
			users.push_back(newUser);
			return;
		}
		else
			std::cout << "The password does not match! Try again!\n";
	}
}

void Shop::addUser(Login user) {
	users.push_back(user);
}

void Shop::addBook()
{
	std::string answerStr;
	int answerInt;
	double answerDouble;

	Book book;

	std::cout << "Title: ";
	std::getline(std::cin, answerStr);
	book.setTitle(answerStr);
	std::cout << "Author: ";
	std::getline(std::cin, answerStr);
	book.setAuthor(answerStr);
	std::cout << "Genre: ";
	std::getline(std::cin, answerStr);
	book.setGenre(answerStr);
	std::cout << "Pages: ";
	std::cin >> answerInt;
	book.setPages(answerInt);
	std::cout << "Price: ";
	std::cin >> answerDouble;
	book.setPrice(answerDouble);
	std::cout << "Quantity: ";
	std::cin >> answerInt;
	book.setQuantity(answerInt);
	std::cout << "Id: ";
	std::cin >> answerInt;
	book.setId(answerInt);

	products.push_back(book);
	std::cout << "Successfully added product!\n";
}




void Shop::userLogin() {
	std::cout << "-------Login-------\n";
	std::string username;
	std::string password;

	while (true) {
		std::cout << "Username: ";
		std::getline(std::cin, username);
		std::cout << "Password: ";
		std::getline(std::cin, password);

		for (int i = 0; i < users.size(); i++)
		{
			if (username == users[i].getUsername()) {
				if (password == users[i].getPassword())
				{
					std::cout << "Successful login!\n";
					currUser.setUsername(username);
					currUser.setPassword(password);
					return;
				}
			}
		}
		std::cout << "Wrong username or password! Try again!\n";
	}
}


void Shop::addProduct(Book& book)
{
	products.push_back(book);
}

void Shop::sortByTitle()
{
	std::vector<std::string> names;
	std::string name;
	for (int i = 0; i < products.size(); i++)
	{
		name = this->products[i].getTitle();
		names.push_back(name);
	}

	sort(names.begin(), names.end());
	int namesCount = 0;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getTitle() == names[namesCount]) {
			products[i].print();
			std::cout << "\n";
			namesCount++;
			i = -1;
			if (namesCount == products.size())
				return;
		}
	}
}

void Shop::sortByPriceASC()
{
	std::vector<double> prices;
	double price;
	for (int i = 0; i < products.size(); i++)
	{
		price = this->products[i].getPrice();
		prices.push_back(price);
	}

	sort(prices.begin(), prices.end());
	double pricesCount = 0;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getPrice() == prices[pricesCount]) {
			products[i].print();
			std::cout << "\n";
			pricesCount++;
			i = -1;
			if (pricesCount == products.size())
				return;
		}
	}
}

void Shop::sortByPriceDSC()
{
	std::vector<double> prices;
	double price;
	for (int i = 0; i < products.size(); i++)
	{
		price = this->products[i].getPrice();
		prices.push_back(price);
	}

	sort(prices.begin(), prices.end(), std::greater<double>());
	double pricesCount = 0;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getPrice() == prices[pricesCount]) {
			products[i].print();
			std::cout << "\n";
			pricesCount++;
			i = -1;
			if (pricesCount == products.size())
				return;
		}
	}
}

void Shop::addToQuantity(std::string title, int quantityToAdd)
{
	for (int i = 0; i < products.size(); i++) {
		if (title == products[i].getTitle()) {
			products[i].addToQuantity(quantityToAdd);
			std::cout << "Successfully added " << quantityToAdd << " '" << title << "'" << " books!\n";
			return;
		}
	}
	std::cout << "There is no book with this title!\n";
}

void Shop::addToCartByTitle(std::string title)
{
	for (int i = 0; i < products.size(); i++) {
		if (title == products[i].getTitle()) {

			if (products[i].getQuantity() == 0) {
				std::cout << "Out of stock!\n";
				return;
			}
			else {
				shoppingCart.addToCart(products[i]);
				std::cout << "\nSuccessfully added product to shopping cart\n";
				products[i].quantityChange();
				return;
			}
		}
	}
	std::cout << "\nThere is no book with this title\n";
}

void Shop::addToFavByTitle(std::string title)
{

	for (int i = 0; i < products.size(); i++) {
		if (title == products[i].getTitle()) {
			favorites.addToFav(products[i]);
			std::cout << "\nSuccessfully added product to favorite products\n";
			return;
		}
	}
	std::cout << "\nThere is no book with this title\n";
}

void Shop::listCartProducts()
{
	shoppingCart.printCartProducts();
}

void Shop::listFavProducts()
{
	favorites.printFavProducts();
}

double Shop::getTotalCost()
{
	return shoppingCart.getTotalCost();
}

void Shop::removeProdById(int id)
{
	int cnt = 0;
	for (int i = 0; i < products.size(); i++)
	{
		if (id == this->products[i].getId()) {
			this->products.erase(this->products.begin() + i);
			cnt++;
		}
	}

	if (cnt == 0) {
		std::cout << "\nProduct with this Id does not exist!\n\n";
	}
	else
		std::cout << "\nSuccessfully removed product!\n";
}

void Shop::printAllUsers()
{
	for (int i = 0; i < users.size(); i++)
	{
		std::cout << users[i].getUsername() << "\n";
	}
}

void Shop::printAllProducts()
{
	for (int i = 0; i < products.size(); i++)
	{
		this->products[i].print();
		std::cout << "\n";
	}
}
