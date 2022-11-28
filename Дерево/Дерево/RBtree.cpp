#include "RBtree.h"
#include <iostream>
#include<queue>
void RBtree::clean(NodeRB* cur) {
	if (cur != nullptr) {
		clean(cur->left);
		clean(cur->right);
		delete cur;
	}
}
RBtree::RBtree() {
	root = nullptr;
}
RBtree::~RBtree() {
	clean(root);
}
void RBtree::leftRotate(NodeRB*& root, NodeRB* x) {
	NodeRB* y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else {
		if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
	}
	y->left = x;
	x->parent = y;
}
void RBtree::rightRotate(NodeRB*& root, NodeRB* y) {
	NodeRB* x = y->left;
	y->left = x->right;
	if (x->right != NULL) {
		x->right->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == NULL) {
		root = y;
	}
	else {
		if (y == y->parent->right) {
			y->parent->right = x;
		}
		else {
			x->parent->left = y;
		}
	}
	x->right = y;
	y->parent = x;
}

void RBtree::insert(NodeRB*& root, NodeRB* node) {
	NodeRB* x = root;
	NodeRB* y = NULL;
	while (x != NULL)
	{
		y = x;
		if (node->data > x->data)
			x = x->right;
		else
			x = x->left;
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->data > y->data)
			y->right = node;
		else
			y->left = node;
	}
	else
		root = node;
	node->color = Red;
	InsertFixUp(root, node);
}
void RBtree::InsertFixUp(NodeRB*& root, NodeRB* node) {
	NodeRB* parent;
	parent = node->parent;
	while (node != root && parent->color == Red)
	{
		NodeRB* gparent = parent->parent;
		if (gparent->left == parent)
		{
			NodeRB* uncle = gparent->right;
			if (uncle != nullptr && uncle->color == Red)
			{
				parent->color = Black;
				uncle->color = Black;
				gparent->color = Red;
				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->right == node)
				{
					leftRotate(root, parent);
					NodeRB* z = node;
					node = parent;
					parent = z;
				}
				rightRotate(root, gparent);
				gparent->color = Red;
				parent->color = Black;
				break;
			}
		}
		else
		{
			NodeRB* uncle = gparent->left;
			if (uncle != nullptr && uncle->color == Red)
			{
				gparent->color = Red;
				parent->color = Black;
				uncle->color = Black;

				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->left == node)
				{
					rightRotate(root, parent);
					NodeRB* z = node;
					node = parent;
					parent = z;
				}
				leftRotate(root, gparent);
				parent->color = Black;
				gparent->color = Red;
				break;
			}
		}
	}
	root->color = Black;
}

void RBtree::RemoveFixUp(NodeRB*& root, NodeRB* node, NodeRB* parent) {
	NodeRB* othernode;
	while ((!node) || node->color == Black && node != root)
	{
		if (parent->left == node)
		{
			othernode = parent->right;
			if (othernode->color == Red)
			{
				othernode->color = Black;
				parent->color = Red;
				leftRotate(root, parent);
				othernode = parent->right;
			}
			else
			{
				if (!(othernode->right) || othernode->right->color == Black)
				{
					othernode->left->color = Black;
					othernode->color = Red;
					rightRotate(root, othernode);
					othernode = parent->right;
				}
				othernode->color = parent->color;
				parent->color = Black;
				othernode->right->color = Black;
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			othernode = parent->left;
			if (othernode->color == Red)
			{
				othernode->color = Black;
				parent->color = Red;
				rightRotate(root, parent);
				othernode = parent->left;
			}
			if ((!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black))
			{
				othernode->color = Red;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!(othernode->left) || othernode->left->color == Black)
				{
					othernode->right->color = Black;
					othernode->color = Red;
					leftRotate(root, othernode);
					othernode = parent->left;
				}
				othernode->color = parent->color;
				parent->color = Black;
				othernode->left->color = Black;
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		node->color = Black;
}

void RBtree::remove(NodeRB*& root, NodeRB* node) {
	NodeRB* child, * parent;
	ColorRB color;
	if (node->left != nullptr && node->right != nullptr)
	{
		NodeRB* replace = node;
		replace = node->right;
		while (replace->left != nullptr)
		{
			replace = replace->left;
		}
		if (node->parent != nullptr)
		{
			if (node->parent->left == node) {
				node->parent->left = replace;
			}
			else {
				node->parent->right = replace;
			}
		}
		else {
			root = replace;
		}
		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		if (parent == node)
			parent = replace;
		else
		{
			if (child != nullptr)
				child->parent = parent;
			parent->left = child;

			replace->right = node->right;
			node->right->parent = replace;
		}
		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;
		if (color == Black)
			RemoveFixUp(root, child, parent);

		delete node;
		return;
	}
		if (node->left != nullptr)
			child = node->left;
		else
			child = node->right;

		parent = node->parent;
		color = node->color;
		if (child)
		{
			child->parent = parent;
		}
		if (parent)
		{
			if (node == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;

		if (color == Black)
		{
			RemoveFixUp(root, child, parent);
		}
		delete node;
}
NodeRB* RBtree::search(NodeRB* node, int data) {
	if (node == nullptr || node->data == data)
		return node;
	else
		if (data > node->data)
			return search(node->right, data);
		else
			return search(node->left, data);
}
void RBtree::preOrder(NodeRB* node) {
	if (node == NULL) {
		return;
	}
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
void RBtree::inOrder(NodeRB* node) {
	if (node == NULL) {
		return;
	}
	inOrder(node->left);
	printf("%d ", node->data);
	inOrder(node->right);
}
void RBtree::postOrder(NodeRB* node) {
	if (node == NULL) {
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	printf("%d ", node->data);
}
void RBtree::BFS(NodeRB* node){
	if (node == nullptr) {
		return;
	}
	std::queue<NodeRB*>cru;
	cru.push(root);
	NodeRB* x;
	while (!cru.empty()) {
		x = cru.front();
		cru.pop();
		printf("%d ", x->data);
		if (x->left != nullptr) {
			cru.push(x->left);
		}
		if (x->right != nullptr) {
			cru.push(x->right);
		}
		
	}
	printf("\n");
}


void RBtree::insert(int data) {
	NodeRB* node = new NodeRB(data, Red, nullptr, nullptr, nullptr);
	insert(root, node);
}
void RBtree::remove(int data) {
	NodeRB* deletenode = search(root, data);
	if (deletenode != NULL)
		remove(root, deletenode);
}
int RBtree::search(int data) {
	NodeRB* z = search(root, data);
	if(z == nullptr)
		return false;
	return true;
}
void RBtree::preOrder() {
	if (root == nullptr) {
		printf("\nempty\n");
	}
	else {
		preOrder(root);
	}
}
void RBtree::postOrder() {
	if (root == nullptr) {
		printf("\nempty\n");
	}
	else {
		postOrder(root);
	}
}
void RBtree::inOrder() {
	if (root == nullptr) {
		printf("\nempty\n");
	}
	else {
		inOrder(root);
	}
}
void RBtree::BFS() {
	if (root == nullptr) {
		printf("\nempty\n");
	}
	else {
		BFS(root);
	}
}
bool RBtree::emply() {
	if (root == nullptr) {
		return true;
	}
	return false;
}