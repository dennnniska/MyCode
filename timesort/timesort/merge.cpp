#include "merge.h"
#include <iostream>
void merge::sort(vector& arr, int start_first, int size_first, int start_second, int size_second) {
	int* left = new int[size_first + 1];
	int* right = new int[size_second + 1];

	for (int i = 0; i < size_first; i++) {
		left[i] = arr[i + start_first];
	}
	left[size_first] = 2147483640;

	for (int i = 0; i < size_second; i++) {
		right[i] = arr[start_second + i];
	}
	right[size_second] = 2147483640;


	int j = 0, k = 0;
	bool is_left = true;
	int galop = 0;
	int r = 1;
	for (int i = start_first; i < start_first + size_second + size_first; i++) {
		if (galop == 7) {

			if (is_left) {
				while (r + j < size_first && left[r + j] <= right[k]) {
					r *= 2;
				}
				r /= 2;
				for (int q = j; q < r + j; q++) {
					arr[i] = left[q];
					i++;
				}
				j += r ;
			}
			else {
				while (r + k < size_second && left[j] > right[k + r]) {
					r *= 2;
				}
				r /= 2;
				for (int q = k; q < r + k; q++) {
					arr[i] = right[q];
					i++;
				}
				k += r ;
			}
			
		}
		if (left[j] > right[k]) {
			arr[i] = right[k];
			k++;
			if (is_left) {
				is_left = false;
				galop = 1;
			}
			else {
				galop++;
			}
		}
		else {
			arr[i] = left[j];
			j++;
			if (!is_left) {
				is_left = true;
				galop = 1;
			}
			else {
				galop++;
			}
		}
		r = 1;

		
	}
	delete[]left;
	delete[]right;
 }