#include "tree.h"
void tree::build(std::string line) {
	int values = 0;
	if (head != nullptr) {
		return;
	}
	head = new Node;
	Node* cur = head;
	Node* next;
	for (int i = 1; i < line.size(); i++) {
		if (line[i] >= '0' && line[i] <= '9') {
			values = values * 10 + line[i] - '0';
		}
		if (line[i] == '(') {
			if (cur->left == nullptr) {
				cur->data = values;
				cur->left = new Node;
				next = cur->left;
				next->last = cur;
				cur = next;
			}
			else {
				cur->right = new Node;
				next = cur->right;
				next->last = cur;
				cur = next;
			}
			values = 0;
		}
		if (line[i] == ')') {
			if (cur->left == nullptr) {
				cur->data = values;
			}
			values = 0;
			cur = cur->last;
		}
	}
}

void tree::DFS_start(Node* cur) {
	if (cur != nullptr) {
		std::cout << cur->data << ' ';
		DFS_start(cur->left);
		DFS_start(cur->right);
	}
}

void tree::DFS_average(Node* cur) {
	if (cur != nullptr) {
		DFS_average(cur->left);
		std::cout << cur->data << ' ';
		DFS_average(cur->right);
	}
}

void tree::DFS_end(Node* cur) {
	if (cur != nullptr) {
		DFS_end(cur->left);
		DFS_end(cur->right);
		std::cout << cur->data << ' ';
	}
}

tree::~tree() {
	if (head != nullptr) {
		clean(head);
	}
}

void tree::clean(Node* cur) {
	if (cur != nullptr) {
		clean(cur->left);
		clean(cur->right);
		delete cur;
	}
}