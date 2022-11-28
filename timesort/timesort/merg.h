#pragma once
#include "vector.h"
#include "chek.h"
#include "stek.h"
class merg
{
private:
	chek chek_stack;
public:
	void sort(vector& arr, int star, int end, stack& merge);
};

