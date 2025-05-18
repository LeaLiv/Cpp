#include<iostream>
#include "List.h"
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
	List(const List& other)
	{
		if (other.isEmpty())
		{
			head = nullptr;
			return;
		}
		//handle first element - special case
		add(other.head->value); //head = new Link(src->value);
		Link* src = other.head;
		Link* trg = head;
		while (src->next != nullptr)//it is not the last element
		{
			trg->next = new Link(src->next->value);
			src = src->next;
			trg = trg->next;
		}
	}
	~List()
	{
		clear();
	}

	// operations
	void add(int value)
	{
		/*if (isEmpty())
		{
			head = new Link(value, nullptr);
		}
		else
		{*/
		head = new Link(value, head);
		//}
	}
	int firstElement() const
	{
		if (!head)
			throw "List is empty, can not return first element";
		return head->value;
	}
	bool search(int value) const
	{
		for (Link* tmp = head;tmp != nullptr; tmp = tmp->next)
		{
			if (tmp->value == value)
				return true;
		}
		return false;
	}
	bool isEmpty() const { return head == nullptr; }
	void removeFirst()
	{
		if (isEmpty()) return;
		Link* tmp = head;
		head = head->next;//head points to second element
		delete tmp;
	}
	void clear()
	{
		while (!isEmpty())
		{
			removeFirst();
		}
	}

private:
	// data field
	Link* head;

};


void List::removeLast()
{

}