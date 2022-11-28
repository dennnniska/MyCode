#pragma once
#include "read_vector.h"
#include "merg.h"
#include "stek.h"
class dif_arr
{
private:
	merg merg_sort;
public:
	void difference(vector& array, int minrun, stack& merge);
};

