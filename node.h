// node.h
// Tree node class

#pragma once

class Node
{
public:
	Node();
	Node(int val);
	int value;
	Node* p_left;
	Node* p_right;
	Node* p_parent;
};

Node::Node() {
	p_left = nullptr;
	p_right = nullptr;
	p_parent = nullptr;
	value = 0;

}

Node::Node(int val) : Node() {
	value = val;
}