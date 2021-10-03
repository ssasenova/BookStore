#pragma once
#include <string>

class Login
{
private:
	std::string username;
	std::string password;

	void copyData(const Login&);
public:
	void setUsername(const std::string&);
	std::string getUsername()const;
	void setPassword(const std::string&);
	std::string getPassword()const;

	Login();
	Login(const std::string&, const std::string&);
	Login(const Login&);
	Login& operator=(const Login&);
};

