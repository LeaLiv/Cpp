#pragma once
#include <string>
using namespace std;

class Account
{
	int accountNumber;
	int code;
	int balance;
	string email;
public:
	Account():accountNumber(0),code(0),balance(0),email(""){}
	Account(int accountNumber, int code, int balance, string email);
	bool isValidEmail(const string& email);
};

