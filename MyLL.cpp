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
	while (head != nullptr) {
		Node* temp = head->next;
		delete head;
		head = temp;
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
	Node* otherhead = other.getHead();
	tail->next = otherhead;
	otherhead->prev = tail;
	Node* curr = tail;
	while (curr != nullptr) {
		curr = curr->next;
	}
	tail = curr;
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
	if (current == tail) return true;
	return false;
}
bool MyLL::getNext(string &str) {
	if (current == nullptr) return false;
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
		add_to_front(temp->value);
		Node *tempnext = temp->next;
		delete (temp);
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
	// TODO: temporary with current, no clue what to do
	if (current == nodetodelete) nodetodelete = nullptr;
	if (nodetodelete->prev == nullptr && nodetodelete-> next == nullptr) {
		delete nodetodelete;
		return;
	};
	if (nodetodelete->prev == nullptr) {
		nodetodelete->next->prev == nullptr;
		delete nodetodelete;
		return;
	}
	if (nodetodelete->next == nullptr) {
		nodetodelete->prev->next == nullptr;
		delete nodetodelete;
		return;
	}
	Node* currprev = nodetodelete->prev;
	Node* currnext = nodetodelete->next;
	currprev->next = currnext;
	currnext->prev = currprev;
	delete nodetodelete;
	return;
}