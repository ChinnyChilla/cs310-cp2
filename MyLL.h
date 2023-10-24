#include <iostream>
#include "Node.h"

using namespace std;

class MyLL {
	public:
		MyLL();
		MyLL(const MyLL &other);
		bool isEmpty();
		bool clear();
		bool add_to_front(const string &);
		bool add_to_back(const string &);
		bool merge(MyLL &other);
		MyLL &operator+=(const MyLL &other);
		MyLL &operator-=(const MyLL &other);
		MyLL &operator=(const MyLL &other);
		int remove(char c);
		bool shift_forward(char c);
		bool reset();
		bool finished();
		bool getNext(string &str);
		Node* getHead() const;
		Node* getTail() const;
		void print();
	private:
		Node *head;
		Node *tail;
		Node *current;
		void deleteNode(Node *nodetodelete);
};