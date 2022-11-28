#pragma once
#include<queue>
enum ColorRB {Black, Red};
	struct NodeRB {
		NodeRB* left;
		NodeRB* right;
		NodeRB* parent;
		ColorRB color;
		int data;
		NodeRB(int d, ColorRB c, NodeRB* p, NodeRB* r, NodeRB* l) {
			data = d;
			color = c;
			parent = p;
			right = r;
			left = l;
		}
	};
class RBtree
{
private:
	
	
	NodeRB* root;
	void leftRotate(NodeRB* &root, NodeRB* x);
	void rightRotate(NodeRB*& root, NodeRB* y);

	void insert(NodeRB*& root, NodeRB* node);
	void InsertFixUp(NodeRB*& root, NodeRB* node);

	void RemoveFixUp(NodeRB*& root, NodeRB* node, NodeRB*parent);
	void remove(NodeRB*& root, NodeRB* node);

	NodeRB* search(NodeRB*node, int data);
	void preOrder(NodeRB*node);
	void inOrder(NodeRB*node);
	void postOrder(NodeRB*node);
	void BFS(NodeRB*node);
	void clean(NodeRB *cur);
public:
	void insert(int data);
	void remove(int data);
	int search(int data);
	void preOrder();
	void postOrder();
	void inOrder();
	void BFS();
	RBtree();
	~RBtree();
	bool emply();
};

