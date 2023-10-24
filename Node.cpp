#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
	value = "Nothing";
	next = nullptr;
	prev = nullptr;
}
Node::Node(string want) {
	value = want;
	next = nullptr;
	prev = nullptr;
}