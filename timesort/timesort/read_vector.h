#pragma once
#include "vector.h"
class read_vector
{
private:
	vector arr;
	int size=0;
public:
	void reader();
	vector& get_arr();
	int get_size();
};

