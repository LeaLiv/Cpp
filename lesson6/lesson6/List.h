#include<iostream>
using namespace std;
#pragma once
//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue) :value(linkValue), next(nullptr) {}
		Link(int linkValue, Link* nextPtr) :value(linkValue), next(nextPtr) {}
		Link(const Link& other) :value(other.value), next(nullptr) {}
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List() { head = nullptr; }
	void removeLast();
	List(const List& other);
	~List();
	// operations
	void add(int value);
	int firstElement() const;	
	bool search(int value) const;	
	bool isEmpty() const { return head == nullptr; }
	void removeFirst();	
	void clear();	

private:
	// data field
	Link* head;
};