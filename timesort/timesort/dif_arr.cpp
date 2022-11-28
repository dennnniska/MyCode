#include "dif_arr.h"
#include "vector.h"
#include "merg.h"
#include <iostream>
#include "stek.h"

void dif_arr::difference(vector &array, int minrun, stack& merge) {
	int start = 0;
	int end = 1;
	bool is_up = true;
	bool first = true;
	for (int i = 1; i < array.size(); i++) {
		if (start - i == -1) {
			if (array[i] >= array[i - 1]) {
				is_up = true;
				first = true;
			}
			else {
				is_up = false;
				first = true;
			}
		}
		else {
			if (array[i] >= array[i - 1] && !is_up && first) {
				first = false;
				for (int j = start; j < (start + i) / 2; j++) {
					array[j] += array[i - j + start];
					array[i+start-j] = array[j] - array[i - j + start];
					array[j] -= array[i + start - j];
				}
				if (end - start >= minrun) {
					merg_sort.sort(array, start, end, merge);
					start = i + 1;
					end = i + 2;
					i++;
				}
			}
			if (array[i] < array[i - 1] && is_up && first) {
				first = false;
				if (end - start >= minrun) {
					merg_sort.sort(array, start, end, merge);
					start = i + 1;
					end = i + 2;
					i++;
				}
			}
		}
		end++;
		if (minrun == end - start && !first) {
			merg_sort.sort(array, start, end, merge);
			start = i + 1;
			end = i + 2;
			i++;
		}
	}
	
	if (start < array.size()) {
		merg_sort.sort(array, start, end, merge);
	}
}