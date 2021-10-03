#include "Login.hpp"

Login::Login() {
	this->username = "";
	this->password = "";
}

Login::Login(const std::string& username, const std::string& password) {
	this->username = username;
	this->password = password;
}

void Login::copyData(const Login& other) {
	this->username = other.username;
	this->password = other.password;
}

void Login::setUsername(const std::string& username) {
	this->username = username;
}

std::string Login::getUsername() const {
	return this->username;
}

void Login::setPassword(const std::string& password) {
	this->password = password;
}

std::string Login::getPassword() const {
	return this->password;
}

Login::Login(const Login& other) {
	copyData(other);
}

Login& Login::operator=(const Login& other) {
	if (this != &other) {
		copyData(other);
	}

	return *this;
}

