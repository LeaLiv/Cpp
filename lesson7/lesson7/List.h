#pragma once
class List
{
public:
	class Link
	{
	public:
		Link(int linkValue) :value(linkValue), next(nullptr) {}
		Link(int linkValue, Link* nextPtr) :value(linkValue), next(nextPtr) {}
		Link(const Link& other) :value(other.value), next(nullptr) {}
		int value;
		Link* next;
	};
	Link* head;
public:
	List();
	List(const List& other);
	~List();
	void push(int value);
	int firstElement() const;
	bool search(int value) const;
	bool isEmpty() const { return head == nullptr; }
	void removeFirst();
	void clear();
	int removeLast();
	void print();
};