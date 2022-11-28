#include "merg.h"
#include "stek.h"
#include <iostream>
#include "chek.h"
void  merg::sort(vector &arr, int start, int end, stack &merge) {
	for (int i = start + 1; i < end; i++) {
		int j = i;
		while (arr[j] < arr[j - 1] && j > start) {
			arr[j] = arr[j - 1] + arr[j];
			arr[j - 1] = arr[j] - arr[j - 1];
			arr[j] = arr[j] - arr[j - 1];
			j--;
		}
	}
	merge.push(start, end - start);
	chek_stack.stack_(arr, merge);
}