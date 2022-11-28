#include <string>
#include "tree.h"
#include "draw.h"
#include "move.h"
#pragma once
class usual
{
private:
	move key;
	draw draw_usual;
	int pos;
	tree _tree;
	int option;
public:
	void usual_tree(std::string line);
};

