#include "Account.h"
#include <iostream>
//#include <string_view> 
//#include <string>
//using namespace std;
double Account::sumWithdra = 0;
double Account::sumDeposit = 0;

Account::Account(int accountNumber, int code, int balance, string email)
{
	checkValidition(code,email);
	this->balance = balance;
	this->code = code;
	this->email = email;
}

bool Account::isValidEmail(const string& email) {
	size_t atPos = email.find('@');
	if (atPos == string::npos || atPos == 0 || atPos == email.length() - 1) return false;

	string localPart = email.substr(0, atPos);
	string domain = email.substr(atPos + 1);

	if (localPart.find(' ') != string::npos || domain.find(' ') != string::npos) return false;
	if (!(domain.ends_with(".com") || domain.ends_with(".co.il"))) return false;

	return true;
}
istream& operator>>(istream& input, Account& account) {
	int tempAccountNumber;
	int tempCode;
	string tempEmail;
	input >> tempAccountNumber >> tempCode >> tempEmail;
	try
	{
		account.checkValidition(tempCode, tempEmail);
		account.accountNumber = tempAccountNumber;
		account.code = tempCode;
		account.email = tempEmail;
		account.balance = 0;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	return input;
}

 void Account::checkValidition(int code, string email)
 {
	 if (code < 1000 || code >9999)
		 throw runtime_error("ERROR: code must be of 4 digits without leading zero!");
	 if (email.find('@') == string::npos)
		 throw runtime_error("ERROR: email must contain @!");
	 if (!isValidEmail(email))
		 throw runtime_error("ERROR: email must have a valid format and end with .com or .co.il!");
	 this->accountNumber = accountNumber;
 }

 void Account::withdraw(int nis)
 {
	 if (balance-nis<(- 6000))
		 throw runtime_error("ERROR: cannot have less than - 6000 NIS!");
	 if (nis < 0)
		 throw runtime_error("ERROR: cannot withdraw a negative amount!");
	 if (nis > 2500)
		 throw runtime_error("ERROR: cannot withdraw more than 2500 NIS!");
	 balance -= nis;
 }

 void Account::deposit(int nis)
 {
	 if (nis > 10000)
		 throw runtime_error("ERROR: cannot deposit more than 10000 NIS!");
	 if (nis < 0)
		 throw runtime_error("ERROR: cannot deposit a negative amount!");
	 balance += nis;
 }
