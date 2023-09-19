// btree.h
// Binary tree class
#pragma once
#include "node.h"

class BTree
{
private:
	Node* top;
public:
	BTree() : top{nullptr} {};
	void display(Node* top);
	Node* insert(int v, Node* n);
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

void BTree::display(Node* n = nullptr) {
	if (n == nullptr) n = this->top;
	if (n == nullptr) return;

	if(n->p_left != nullptr)
		display(n->p_left);

	std::cout << n->value << " ";
	if(n->p_right != nullptr)
		display(n->p_right);
}