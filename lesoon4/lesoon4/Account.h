#pragma once
#include <string>
using namespace std;

class Account
{
	int accountNumber;
	int code;
	int balance;
	string email;
	static double sumWithdra;
	static double sumDeposit;
	
public:
	Account():accountNumber(0),code(0),balance(0),email(""){}
	Account(int accountNumber, int code, int balance, string email);
	bool isValidEmail(const string& email);
	int getAccountNumber() { return accountNumber; }
	int getCode() { return code; }
	int getBalance() { return balance; }
	string getEmail() { return email; }
	friend istream& operator>>(istream& input,Account& account);
	void checkValidition(int code, string email);
	void withdraw(int nis);
	void deposit(int nis);
	static int getSumWithdraw() { return sumWithdra; }
	static int getSumDeposit() { return sumDeposit; }
};

