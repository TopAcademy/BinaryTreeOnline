
#include <iostream>
#include "btree.h"
using namespace std;

int main()
{
	BTree tree;
	tree.insert_nr(8);
	tree.insert_nr(3);
	tree.insert_nr(10);
	tree.insert_nr(13);
	tree.insert_nr(1);
	tree.insert_nr(4);
	tree.insert_nr(2);

	tree.display();
	cout << endl;
	tree.display_nr();
	cout << endl;
	if (tree.find(14) == nullptr)
		cout << "not found";
	else
		cout << tree.find(14)->value;

}

/*
           8
          / \
        3     10
       / \      \
	 1	  4      13
	  \
	   2
*/