// btree.h
// Binary tree class
#pragma once
#include <stack>
#include "node.h"

class BTree
{
private:
	Node* top;
public:
	// Constructors
	BTree() : top{nullptr} {};
	// Display methods
	void display(Node* top);		// display tree with recursion
	void display_nr();				// display tree WITHOUT recursion
	// Elements edit
	Node* insert(int v, Node* n);	// insert element with recursion
	Node* insert_nr(int v);			// insert element WITHOUT recursion
	// Search metods
	void find(int v);
};

// Insert new node to the tree
Node* BTree::insert(int v, Node * n = nullptr)
{
	Node * i = new Node (v);
	if (top == nullptr && n == nullptr) {
		top = i;
		return top;
	}
	if (n == nullptr)
		n = top;

	if (i->value < n->value) {
		//Go to left
		if (n->p_left == nullptr)
		{
			//end of end
			n->p_left = i;
			i->p_parent = n;
			return n->p_left;
		}
		else
			insert(v, n->p_left);
	}
	else {
		// Go to right
		if (n->p_right == nullptr) {
			//end of end
			n->p_right = i;
			i->p_parent = n;
			return n->p_right;
		}
		else
		insert(v, n->p_right);
	}
}


// Insert new node (X method without recursion)
//
Node* BTree::insert_nr(int v)
{
	Node* x = new Node(v);		// node to insert
	Node* c = this->top;		// current node
	if (c == nullptr) {
		// if tree is empty
		this->top = x;
		return x;
	}
	while (true) {
		if (x->value < c->value) {
			// Look to left side
			if (!c->p_left) {
				// insert to the left and break
				c->p_left = x;
				x->p_parent = c;
				return x;
			}
			else {
				// go down to the left and continue
				c = c->p_left;
				continue;
			}
		}
		else if (x->value > c->value) {
			// Look to right side
			if (!c->p_right) {
				// insert to the right and break
				c->p_right = x;
				x->p_parent = c;
				return x;
			}
			else {
				// go down to the right and continue
				c = c->p_right;
				continue;
			}
		}
	}
}


// Display tree (V method with recursion)
//
void BTree::display(Node* n = nullptr) 
{
	if (n==nullptr) std::cout << "Displaying the tree with recursion" << std::endl;
	if (n == nullptr) n = this->top;
	if (n == nullptr) return;

	if(n->p_left != nullptr)
		display(n->p_left);

	std::cout << n->value << " ";
	if(n->p_right != nullptr)
		display(n->p_right);
}


// Display tree (X method without recursion)
//
void BTree::display_nr()
{
	std::cout << "Displaying the tree without recursion" << std::endl;
	Node* n = this->top;			// start from top node
	if (n == nullptr) return;		// if the tree is empty
	std::stack<Node*> st;
	do {
		if ((!st.empty()) && (n == st.top())) {
			// we came back
			st.pop();
		}
		else if (n->p_left) {
			// we arrived the node first time
			st.push(n);
			n = n->p_left;
			continue;
		}
		std::cout << n->value << ", ";
		if (n->p_right) {
			n = n->p_right;
			continue;
		}
		else {
			// go back (up)
			if (!st.empty()) {
				n = st.top();
				continue;
			}
			else n = nullptr;
		}
	} while (n);

}

