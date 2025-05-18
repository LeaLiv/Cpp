#include <iostream>
#include "List.h"
#include <stack>
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
	if (head == nullptr) {
		head = new Link(value);
		return;
	}
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
		cout << tmp->value << endl;
	}
}

void List::pushFront(int value)
{
	if (head == nullptr){
		head = new Link(value);
		return;
	}
	Link* tmp = new Link(value);
	tmp->next = head;
	head = tmp;

}

List List::operator+(const List& list) const
{
	List result;
	Link* tmp = head;
	stack<int> thisStack, otherStack;
	while (tmp != nullptr) {
		thisStack.push(tmp->value);
		tmp = tmp->next;
	}
	tmp = list.head;
	while (tmp != nullptr) {
		otherStack.push(tmp->value);
		tmp = tmp->next;
	}
	int carry = 0, num, val1, val2;
	while (!thisStack.empty() || !otherStack.empty() || carry != 0) {
		val1 = val2 = 0;
		if (!thisStack.empty()) {
			val1 = thisStack.top();
			thisStack.pop();
		}
		if (!otherStack.empty()) {
			val2 = otherStack.top();
			otherStack.pop();
		}
		num = val1 + val2+carry;
		carry = num / 10;
		result.pushFront(num % 10);

	}
	return result;
}
