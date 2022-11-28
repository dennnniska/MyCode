#pragma once
#include "read_vector.h"
#include "get_minrun.h"
#include "dif_arr.h"
#include "merge.h"
#include "print_array.h"
#include "stek.h"
class Timsort
{
private:
	dif_arr sort1;
	stack merge_;
	int minrun = 0;
	get_minrun soft_minrun;
	vector array;
	merge sort_;
	print_array cout_arr;
public:
	void sort(read_vector& arr);
};

