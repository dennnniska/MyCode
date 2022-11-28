#include <string>
#include <iostream>
#pragma once
class tree
{
private:
	struct Node {
		Node* left = nullptr;
		Node* right = nullptr;
		Node* last = nullptr;
		int data = 0;
	};
	Node* head;
public:
	void build(std::string line);
	void BFS();
	void DFS_start(Node* cur);
	void DFS_average(Node* cur);
	void DFS_end(Node* cur);
	Node* get_head() { return head; };
	~tree();
	void clean(Node *cur);

};

