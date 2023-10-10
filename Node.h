#include <iostream>
using namespace std;

class Node {
	public:
		string value;
		Node *next;
		Node *prev;
		Node();
		Node(string value);
};