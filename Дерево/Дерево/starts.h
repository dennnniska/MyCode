#include"read.h"
#include"BR_tree.h"
#include"check.h"
#include"move.h"
#include<string>
#include "draw.h"
#include "usual.h"
#include<iostream>
#pragma once
class starts
{
public:
	void main();
private:
	BR_tree BRtree_;
	usual tree_us;
	move key;
	int option;
	draw console;
	int pos;
	std::string line;
	bool is_ok;
	check checks;
	read reader;
};

