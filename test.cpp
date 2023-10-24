#include <iostream>
#include <string>
#include <cassert>
#include "MyLL.h"

int main()
{
	// Guideline to use the following test cases:
	//  1.If you have any other test code/main function comment it out.
	//  2.Use this main function.
	//  3.Make sure to include appropriate header files.
	//  4.You may need to make changes in the make file.

	// Test case 1 ->
	// Goal : To test if all the implemented methods are behaving as expected.

	MyLL list1;
	MyLL list2;
	std::string item;

	// Test isEmpty() on an empty list
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	// Test clear()
	list1.add_to_back("Bob");
	list1.add_to_front("Eve");
	list1.clear();
	assert(list1.isEmpty());

	// Test add_to_front()
	list1.add_to_front("Alice");
	list1.add_to_front("Eve");
	list1.add_to_front("Bob");
	assert(!list1.isEmpty());
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Eve");
	assert(list1.getNext(item) && item == "Alice");
	assert(!list1.getNext(item)); // After the last item, getNext should return false.
	list1.clear();
	assert(list1.isEmpty());

	// Test add_to_back()
	list1.add_to_back("Bob");
	list1.add_to_back("Charlie");
	list1.add_to_back("Alice");
	assert(!list1.isEmpty());
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Charlie");
	assert(list1.getNext(item) && item == "Alice");

	// Test merge()
	list2.add_to_back("David");
	list2.add_to_back("Eve");
	list1.merge(list2);
	list1.reset();
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Charlie");
	assert(list1.getNext(item) && item == "Alice");
	assert(list1.getNext(item) && item == "David");
	assert(list1.getNext(item) && item == "Eve");
	assert(!list1.isEmpty());
	assert(list2.isEmpty()); // Merge should leave other list empty
	list1.clear();
	assert(list1.isEmpty());

	// Test operator+=
	list1.add_to_back("Alice");
	list1.add_to_back("Bob");
	list2.add_to_back("David");
	list2.add_to_back("Eve");
	list1 += list2;
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Alice");
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "David");
	assert(list1.getNext(item) && item == "Eve");
	assert(!list1.isEmpty());
	assert(!list2.isEmpty()); //+= should leave other list intact
	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	// Test operator-=
	list1.add_to_back("Alice");
	list1.add_to_back("Bob");
	list2.add_to_back("Bob");
	list1 -= list2;
	list1.reset(); // reset to set iterator to first node
	list2.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Alice");
	assert(!list2.isEmpty()); //-= should leave other list intact
	assert(list2.getNext(item) && item == "Bob");
	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	// Test remove()
	list1.add_to_back("Charlie");
	list1.add_to_back("David");
	list1.add_to_back("Eve");
	list1.add_to_back("Chumlee");
	int count = list1.remove('C');
	assert(count == 2);
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "David");
	assert(list1.getNext(item) && item == "Eve");
	list1.clear();
	assert(list1.isEmpty());

	// Test shift_forward()
	list1.add_to_back("Alice");
	list1.add_to_back("Bob");
	list1.add_to_back("Charlie");
	list1.add_to_back("David");
	list1.add_to_back("Eve");
	list1.shift_forward('D');
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "David");
	assert(list1.getNext(item) && (item == "Alice" || item == "Bob" || item == "Charlie" || item == "Eve"));
	assert(list1.getNext(item) && (item == "Alice" || item == "Bob" || item == "Charlie" || item == "Eve"));
	assert(list1.getNext(item) && (item == "Alice" || item == "Bob" || item == "Charlie" || item == "Eve"));
	assert(list1.getNext(item) && (item == "Alice" || item == "Bob" || item == "Charlie" || item == "Eve"));
	list1.clear();

	// Test iterator
	list1.add_to_back("David");
	list1.add_to_back("Alice");
	list1.add_to_back("Bob");
	list1.add_to_back("Charlie");
	list1.add_to_back("Eve");
	list1.add_to_back("Alpha");
	list1.add_to_back("Beta");
	list1.add_to_back("Gamma");

	list1.reset();
	assert(list1.getNext(item) && item == "David");
	assert(list1.getNext(item) && item == "Alice");
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Charlie");
	assert(list1.getNext(item) && item == "Eve");
	assert(list1.getNext(item) && item == "Alpha");
	assert(list1.getNext(item) && item == "Beta");
	assert(list1.getNext(item) && item == "Gamma");
	assert(!list1.getNext(item));

	std::cout << "All tests passed from section 1" << std::endl;

	// Test case 2 ->
	// Goal : Test whether 'add_to_back' and 'add_to_front' support a large number of insertions.

	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	for (int i = 0; i < 100; i++)
	{
		list1.add_to_front("Item " + std::to_string(i));
	}

	for (int i = 0; i < 100; i++)
	{
		list1.add_to_back("Item " + std::to_string(100 + i));
	}
	assert(!list1.isEmpty());

	list1.reset(); // reset to set iterator to first node
	for (int i = 99; i >= 0; i--)
	{
		assert(list1.getNext(item) && item == "Item " + std::to_string(i));
	}

	for (int i = 100; i < 200; i++)
	{
		assert(list1.getNext(item) && item == "Item " + std::to_string(i));
	}

	std::cout << "All tests passed from section 2" << std::endl;

	// Test case 3 ->
	// Goal : Test whether merge fails when a list is merged to itself.

	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	list1.add_to_back("Bob");
	list1.add_to_back("Eve");

	list1.add_to_back("John");
	list1.add_to_back("Sam");
	list1.add_to_back("David");

	list1.merge(list1);
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Eve");
	assert(list1.getNext(item) && item == "John");
	assert(list1.getNext(item) && item == "Sam");
	assert(list1.getNext(item) && item == "David");
	assert(!list1.getNext(item));

	std::cout << "All tests passed from section 3" << std::endl;

	// Test case 4 ->
	// Goal : Shift forward Operation

	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	list1.add_to_back("Bob");
	list1.add_to_back("Eve");

	list1.add_to_back("Barbara");
	list1.add_to_back("Sam");
	list1.add_to_back("Becky");

	list1.shift_forward('B');
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && (item == "Bob" || item == "Barbara" || item == "Becky"));
	assert(list1.getNext(item) && (item == "Bob" || item == "Barbara" || item == "Becky"));
	assert(list1.getNext(item) && (item == "Bob" || item == "Barbara" || item == "Becky"));
	assert(list1.getNext(item) && (item == "Eve" || item == "Sam"));
	assert(list1.getNext(item) && (item == "Eve" || item == "Sam"));

	std::cout << "All Tests passes from section 4" << std::endl;

	// Test case 5 ->
	// Goal : isFinished returns true

	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	list1.add_to_back("Bob");
	list1.add_to_back("Eve");

	list1.add_to_back("Barbara");
	list1.add_to_back("Sam");
	list1.add_to_back("Becky");

	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Bob");
	assert(list1.getNext(item) && item == "Eve");
	assert(list1.getNext(item) && item == "Barbara");
	assert(list1.getNext(item) && item == "Sam");
	assert(list1.getNext(item) && item == "Becky");
	assert(!list1.getNext(item));
	assert(list1.finished());

	std::cout << "All Tests passes from section 5" << std::endl;

	// Test case 6 ->
	// Goal : To remove some elements from the list;

	list1.clear();
	list2.clear();
	assert(list1.isEmpty());
	assert(list2.isEmpty());

	list1.add_to_back("Bob");
	list1.add_to_back("Eve");

	list1.add_to_back("Barbara");
	list1.add_to_back("Sam");
	list1.add_to_back("Becky");

	list1.remove('B');
	list1.reset(); // reset to set iterator to first node
	assert(list1.getNext(item) && item == "Eve");
	assert(list1.getNext(item) && item == "Sam");
	assert(!list1.getNext(item));

	assert(list1.finished());

	std::cout << "All Tests passes from section 6" << std::endl;


	std::cout << "testing custom" << std::endl;

	MyLL dll_obj;
	MyLL dll_obj_2;
	dll_obj.add_to_front("3");
	dll_obj.add_to_front("2");
	dll_obj.add_to_front("1");
	dll_obj.reset();
	assert(dll_obj.getNext(item) && item == "1");
	assert(dll_obj.getNext(item) && item == "2");
	assert(dll_obj.getNext(item) && item == "3");
	dll_obj.clear();
	assert(dll_obj.isEmpty());
	dll_obj.add_to_back("1");
	dll_obj.add_to_back("2");
	dll_obj.add_to_back("3");
	dll_obj.reset();
	assert(dll_obj.getNext(item) && item == "1");
	assert(dll_obj.getNext(item) && item == "2");
	assert(dll_obj.getNext(item) && item == "3");
	MyLL dll_obj_other;
	dll_obj_other.add_to_back("a");
	dll_obj_other.add_to_back("b");
	dll_obj_other.add_to_back("c");
	dll_obj.merge(dll_obj_other);
	assert(dll_obj_other.isEmpty());
	dll_obj.reset();
	assert(dll_obj.getNext(item) && item == "1");
	assert(dll_obj.getNext(item) && item == "2");
	assert(dll_obj.getNext(item) && item == "3");
	assert(dll_obj.getNext(item) && item == "a");
	assert(dll_obj.getNext(item) && item == "b");
	assert(dll_obj.getNext(item) && item == "c");

	dll_obj_other.add_to_back("a");
	dll_obj_other.add_to_back("b");
	dll_obj_other.add_to_back("c");
	dll_obj += dll_obj_other;
	dll_obj.reset();
	assert(dll_obj.getNext(item) && item == "1");
	assert(dll_obj.getNext(item) && item == "2");
	assert(dll_obj.getNext(item) && item == "3");
	assert(dll_obj.getNext(item) && item == "a");
	assert(dll_obj.getNext(item) && item == "b");
	assert(dll_obj.getNext(item) && item == "c");
	assert(dll_obj.getNext(item) && item == "a");
	assert(dll_obj.getNext(item) && item == "b");
	assert(dll_obj.getNext(item) && item == "c");
	dll_obj_other.reset();
	assert(dll_obj_other.getNext(item) && item == "a");
	assert(dll_obj_other.getNext(item) && item == "b");
	assert(dll_obj_other.getNext(item) && item == "c");

	MyLL dll_obj_tmp;
	dll_obj_tmp.add_to_back("1");
	dll_obj_tmp.add_to_back("2");
	dll_obj_tmp.add_to_back("c");
	dll_obj -= dll_obj_tmp;
	dll_obj.reset();
	assert(dll_obj.getNext(item) && item == "3");
	assert(dll_obj.getNext(item) && item == "a");
	assert(dll_obj.getNext(item) && item == "b");
	assert(dll_obj.getNext(item) && item == "a");
	assert(dll_obj.getNext(item) && item == "b");

	MyLL dll_obj_3;
	dll_obj_3.add_to_back("k_1");
	dll_obj_3.add_to_back("n_1");
	dll_obj_3.add_to_back("n_2");
	dll_obj_3.add_to_back("k_2");
	dll_obj_3.add_to_back("k_3");
	dll_obj_3.add_to_back("m_1");
	dll_obj_3.add_to_back("n_3");
	dll_obj_3.add_to_back("n_4");
	dll_obj_3.add_to_back("k_4");

	dll_obj_3.remove('k');
	// expects {n_1, n_2, m_1, n_3, n_4}
	dll_obj_3.reset();
	assert(dll_obj_3.getNext(item) && item == "n_1");
	assert(dll_obj_3.getNext(item) && item == "n_2");
	assert(dll_obj_3.getNext(item) && item == "m_1");
	assert(dll_obj_3.getNext(item) && item == "n_3");
	assert(dll_obj_3.getNext(item) && item == "n_4");
	dll_obj_3.remove('n');
	dll_obj_3.reset();
	assert(dll_obj_3.getNext(item) && item == "m_1");
	// expects {m_1}
	dll_obj_3.remove('m');
	dll_obj_3.reset();
	assert(dll_obj_3.isEmpty());
	// expects {}

	dll_obj_2.clear();
	dll_obj_2.add_to_back("k_1");
	dll_obj_2.add_to_back("n_1");
	dll_obj_2.add_to_back("n_2");
	dll_obj_2.add_to_back("k_2");
	dll_obj_2.add_to_back("m_1");
	dll_obj_2.add_to_back("k_3");
	dll_obj_2.add_to_back("n_3");
	dll_obj_2.add_to_back("n_4");
	dll_obj_2.add_to_back("k_4");

	dll_obj_2.shift_forward('k');
	dll_obj_2.reset();
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "m_1"));
	dll_obj_2.shift_forward('n');
	dll_obj_2.reset();
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4" || item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4" || item == "m_1"));
	dll_obj_2.shift_forward('m');
	dll_obj_2.reset();
	assert(dll_obj_2.getNext(item) && (item == "m_1"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "n_1" || item == "n_2" || item == "n_3" || item == "n_4" || item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));

	dll_obj_2.clear();
	dll_obj_2.add_to_back("k_1");
	dll_obj_2.add_to_back("k_2");
	dll_obj_2.add_to_back("k_3");
	dll_obj_2.add_to_back("k_4");
	dll_obj_2.shift_forward('n');
	dll_obj_2.reset();
	assert(dll_obj_2.getNext(item) && (item == "k_1"));
	assert(dll_obj_2.getNext(item) && (item == "k_2"));
	assert(dll_obj_2.getNext(item) && (item == "k_3"));
	assert(dll_obj_2.getNext(item) && (item == "k_4"));
	dll_obj_2.shift_forward('k');
	dll_obj_2.reset();
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));
	assert(dll_obj_2.getNext(item) && (item == "k_1" || item == "k_2" || item == "k_3" || item == "k_4"));

	dll_obj_2.clear();

	bool b3 = dll_obj_2.reset(); // expects b3 to be false
	assert(!b3);

	dll_obj_2.add_to_back("k_1");
	dll_obj_2.add_to_back("k_2");
	dll_obj_2.add_to_back("k_3");
	dll_obj_2.add_to_back("k_4");

	bool b4 = dll_obj_2.reset(); // expects b4 to be true
	assert(b4);

	string next_val;

	bool b5 = dll_obj_2.getNext(next_val); // expects next_val to be k_1, expects b5 to be true
	assert(next_val == "k_1" && b5);
	dll_obj_2.getNext(next_val);		   // expects next_val to be k_2
	assert(next_val == "k_2");
	bool b6 = dll_obj_2.finished();		   // expects b6 to be false
	assert(!b6);
	dll_obj_2.getNext(next_val);		   // expects next_val to be k_3
	assert(next_val == "k_3");
	dll_obj_2.getNext(next_val);		   // expects next_val to be k_4
	assert(next_val == "k_4");
	bool b7 = dll_obj_2.finished();		   // expects b7 to be true
	assert(b7);

	bool b8 = dll_obj_2.getNext(next_val); // expects next_val to be undefined, expects b8 to be false
	assert(next_val == "" && !b8);

	dll_obj_2.reset();
	dll_obj_2.getNext(next_val); // expects next_val to be k_1
	assert(next_val == "k_1");
	return 0;
}