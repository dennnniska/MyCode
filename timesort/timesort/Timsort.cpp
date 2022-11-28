#include "Timsort.h"
#include "dif_arr.h"
#include "chek.h"
#include <iostream>
#include "merge.h"
#include "stek.h"
void Timsort::sort(read_vector& arr) {
	minrun=soft_minrun.minrun(arr.get_size());
	array = arr.get_arr();
	sort1.difference(array, minrun, merge_);
	while (merge_.get_size() > 1) {
		int second_numb = merge_.check_data();
		int second_size = merge_.check_size();
		merge_.pop();
		int first_numb = merge_.check_data();
		int first_size = merge_.check_size();
		merge_.pop();
		sort_.sort(array, first_numb, first_size, second_numb, second_size);
		merge_.push(first_numb, first_size);
	}
	//cout_arr.print_(array);
}