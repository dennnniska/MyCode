#include<iostream>
#pragma once
class queue
{
private:
	int* mas;
	int start;
	int end;
	int size;
public:
	void pop();
	void push(int index = 0);
	int front();
	bool size_();
	queue();
	~queue();
};

