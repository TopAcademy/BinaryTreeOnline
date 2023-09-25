
#include <iostream>
#include "btree.h"
using namespace std;

int main()
{
	BTree tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(10);
	tree.insert(13);
	tree.insert(1);
	tree.insert(4);
	tree.insert(2);

	tree.display();
	cout << endl;
	tree.display_nr();
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