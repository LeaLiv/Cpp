// lesson7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
#include "Calculator.h"
using namespace std;

int main()
{
	/*
	List* lst = new List();
	lst->push(10);
	lst->print();
	cout << lst->removeLast() << endl;
	//lst->print();
	lst->push(9);
	lst->push(8);
	lst->push(7);
	cout << lst->removeLast() << endl;
	cout << "-----------------------\n";
	List a, b;
	a.pushFront(9);
	a.pushFront(2);
	a.pushFront(4); // 429

	b.pushFront(2);
	b.pushFront(3);
	b.pushFront(8); // 832

	List sum = a + b;
	sum.print();*/
	Calculator a = Calculator(5, 8);
	
	Calculator b = Calculator(4.5, 18.9);
	Calculator c = Calculator(25.45789545, 12.365478);
	cout << "-------a---------\n";
	cout << a.add() << endl;
	cout << a.subtract() << endl;
	cout << a.multiply() << endl;
	cout << a.divide() << endl;
	cout << "-------b---------\n";
	cout << b.add() << endl;
	cout << b.subtract() << endl;
	cout << b.multiply() << endl;
	cout << b.divide() << endl;
	cout << "-------c---------\n";
	cout << c.add() << endl;
	cout << c.subtract() << endl;
	cout << c.multiply() << endl;
	cout << c.divide() << endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
