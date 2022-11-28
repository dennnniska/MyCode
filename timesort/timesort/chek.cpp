#include "chek.h"
#include "vector.h"
#include "merge.h"
#include <iostream>
#include "stek.h"

void chek::stack_(vector& arr, stack& merge_) {
	if (merge_.get_size() < 3) {
		return;
	}
	int three_numb = merge_.check_data();
	int three_size = merge_.check_size();
	merge_.pop();
	int second_numb = merge_.check_data();
	int second_size = merge_.check_size();
	merge_.pop();
	int first_numb = merge_.check_data();
	int first_size = merge_.check_size();
	merge_.pop();
	if (first_size > second_size + three_size && second_size > three_size) {
		merge_.push(first_numb, first_size);
		merge_.push(second_numb, second_size);
		merge_.push(three_numb, three_size);
		return;
	}
	if (first_size > three_size) {
		soft_sort.sort(arr, second_numb, second_size, three_numb, three_size);
		merge_.push(first_numb, first_size);
		merge_.push(second_numb, second_size + three_size);
	}
	else {
		soft_sort.sort(arr, first_numb, first_size, second_numb, second_size);
		merge_.push(first_numb, first_size + second_size);
		merge_.push(three_numb, three_size);
	}
}