#include <iostream>
#include <cstring>
#include "MyLL.h"

using namespace std;

MyLL::MyLL() {
	head = nullptr;
	tail = nullptr;
	current = nullptr;
}
MyLL::MyLL(const MyLL& other) {
	head = nullptr;
	tail = nullptr;
	current = nullptr;
	Node* othertemp = other.getHead();
	while (othertemp != nullptr) {
		add_to_back(othertemp->value);
		othertemp = othertemp->next;
	}
}
bool MyLL::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	return false;
}
bool MyLL::clear() {
	Node* temp = head;
	while (temp != nullptr) {
		Node* temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = nullptr;
	tail = nullptr;
	current = nullptr;
	return true;
}
bool MyLL::add_to_front(const string &want) {
	Node *temp = new Node(want);
	if (head == nullptr && tail == nullptr) {
		head = temp;
		tail = temp;
		return true;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;
	return true;
}
bool MyLL::add_to_back(const string &want)
{
	Node *temp = new Node(want);
	if (head == nullptr && tail == nullptr)
	{
		head = temp;
		tail = temp;
		return true;
	}
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	return true;
}
bool MyLL::merge(MyLL &other) {
	if (this == &other) {return false;}
	Node* otherhead = other.getHead();
	Node* othertail = other.getTail();
	tail->next = otherhead;
	otherhead->prev = tail;
	tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
	return true;
}
MyLL& MyLL::operator+=(const MyLL& other) {
	if (this == &other) {
		return *this;
	}
	Node *otherhead = other.getHead();
	while (otherhead != nullptr) {
		add_to_back(otherhead->value);
		otherhead = otherhead->next;
	}
	return *this;
}
MyLL &MyLL::operator-=(const MyLL &other)
{
	if (this == &other)
	{
		return *this;
	}
	Node* othertemp = other.getHead();
	while (othertemp != nullptr) {
		Node* temp = head;
		while (temp != nullptr) {
			if (othertemp->value == temp->value) {
				Node* temptemp = temp->next;
				if (head == temp) {head = head->next;}
				if (tail == temp) { tail = tail->prev;}
				deleteNode(temp);
				temp = temptemp;
				continue;
			}
			temp = temp->next;
		}
		othertemp = othertemp->next;
	}
	return *this;
}
MyLL &MyLL::operator=(const MyLL &other) {
	if (this == &other) return *this;
	head = nullptr;
	tail = nullptr;
	current = nullptr;
	Node *othertemp = other.getHead();
	while (othertemp != nullptr)
	{
		add_to_back(othertemp->value);
		othertemp = othertemp->next;
	}
	return *this;
}
bool MyLL::reset() {
	if (head == nullptr) return false;
	current = head;
	return true;
}
bool MyLL::finished() {
	if (current == nullptr) return true;
	return false;
}
bool MyLL::getNext(string &str) {
	if (current == nullptr) {
		str = "";
		return false;
	}
	str = current->value;
	current = current->next;
	return true;
}
int MyLL::remove(char c) {
	int count = 0;
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->value[0] != c) {
			temp = temp->next;
			continue;
		}
		Node *tempnext = temp->next;
		deleteNode(temp);
		temp = tempnext;
		count++;
	}
	return count;
}
bool MyLL::shift_forward(char c) {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->value[0] != c) {
			temp = temp->next;
			continue;
		}
		if (tail == temp) {tail = tail->prev;}
		add_to_front(temp->value);
		Node *tempnext = temp->next;
		deleteNode(temp);
		temp = tempnext;
	}
	return true;
}

Node* MyLL::getHead() const {
	return this->head;
}
Node *MyLL::getTail() const
{
	return this->tail;
}

void MyLL::deleteNode(Node *nodetodelete) {
	// reseting current if current node is deleted
	if (current == nodetodelete) nodetodelete = nullptr;
	// deleting last node in the list
	if (nodetodelete->prev == nullptr && nodetodelete-> next == nullptr) {
		delete nodetodelete;
		head = nullptr;
		tail = nullptr;
		return;
	};
	// deleting head
	if (nodetodelete->prev == nullptr) {
		nodetodelete->next->prev = nullptr;
		head = nodetodelete->next;
		delete nodetodelete;
		return;
	}
	// deleting tail
	if (nodetodelete->next == nullptr) {
		nodetodelete->prev->next = nullptr;
		tail = nodetodelete->prev;
		delete nodetodelete;
		return;
	}
	// deleting any other node with nodes on either side
	Node* currprev = nodetodelete->prev;
	Node* currnext = nodetodelete->next;
	currprev->next = currnext;
	currnext->prev = currprev;
	delete nodetodelete;
	return;
}

void MyLL::print() {
	Node *temp = head;
	cout << "this is head:" << head << endl;
	cout << "this is tail: " << tail << endl;
	cout << "this is current: " << current << endl;
	cout << "printing nodes" << endl;
	while (temp != nullptr) {
		cout << temp->value << endl;
		cout << "address is: " << temp << endl;
		cout << "temp->next: " << (temp->next) << endl;
		temp = temp->next;
		
	}
	return;
}