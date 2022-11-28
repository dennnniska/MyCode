#pragma once
#include<string>
#include"RBtree.h"
#include"draw.h"
#include"move.h"
class BR_tree
{
public:
	void usual_tree(std::string line);
private:
	int values;
	int option;
	move key;
	draw draw_usual;
	RBtree tree;
	int pos;
	void build(std::string line);
};

