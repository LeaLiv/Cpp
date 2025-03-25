#include "Account.h"
#include <iostream>
//#include <string_view> 
//#include <string>
//using namespace std;

Account::Account(int accountNumber, int code, int balance, string email)
{
	if(code<1000 || code >9999 )
		std::cout << "Hello World!\n";
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
