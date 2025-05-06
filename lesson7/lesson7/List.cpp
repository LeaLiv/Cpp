#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	head = nullptr;
}

List::List(const List& other)
{
	if (other.isEmpty())
	{
		head = nullptr;
		return;
	}
	push(other.head->value);
	Link* src = other.head;
	Link* trg = head;
	while (src->next != nullptr)//it is not the last element
	{
		trg->next = new Link(src->next->value);
		src = src->next;
		trg = trg->next;
	}
}

List::~List()
{
	clear();
}

void List::push(int value)
{
	if (head == nullptr)
		head = new Link(value);
	Link* tmp;
	for (tmp = head; tmp->next != nullptr; tmp = tmp->next);
	tmp->next = new Link(value);
}

int List::firstElement() const
{
	if (!head)
		throw "List is empty, can not return first element";
	return head->value;
}

bool List::search(int value) const
{
	for (Link* tmp = head; tmp != nullptr; tmp = tmp->next)
	{
		if (tmp->value == value)
			return true;
	}
	return false;
}

void List::removeFirst()
{
	if (isEmpty()) return;
	Link* tmp = head;
	head = head->next;
	delete tmp;
}

void List::clear()
{
	while (!isEmpty())
	{
		removeFirst();
	}
}

int List::removeLast()
{
	if (head == nullptr)
		return -1;
	if (head->next == nullptr)
	{
		Link* node = head;
		head = nullptr;
		//cout << node->value<<"\n";
		return node->value;
	}
	for (Link* tmp = head; tmp != nullptr; tmp = tmp->next)
	{
		if (tmp->next->next == nullptr) {
			Link* node = tmp->next;
			tmp->next = nullptr;
			cout << node->next;
			return node->value;
		}
	}
	return -1;
}

void List::print()
{
	for (Link* tmp = head; tmp != nullptr; tmp = tmp->next) {
		cout << tmp->value<<endl;
	}
}
