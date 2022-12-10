#include "sort.h"
void sort::sortMR(ver_sm* mas, int kol) {
	//sortMR(mas, 0, kol - 1);
	ver_sm z;
	for (int i = 0; i < kol - 1; i++) {
		for (int j = 0; j < kol - i - 1; j++) {
			if (mas[j].ves > mas[j + 1].ves) {
				z = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = z;
			}
		}
	}
}
/*void sort::sortMR(ver_sm* mas, int start, int end) {
	if (start < end) {
		mid = (start + end + 1) / 2;
		sortMR(mas, start, mid);
		sortMR(mas, mid + 1, end);
		build(mas, start, mid, end);
	}
}
void sort::build(ver_sm* mas, int start, int mid, int end) {
	ver_sm * left = new ver_sm[mid - start + 2];
	for (int i = start; i <= mid; i++) {
		left[i - start] = mas[i];
	}
	left[mid - start + 1].ves = 2147483640;
	ver_sm* right = new ver_sm[end - mid + 1];
	for (int i = mid + 1; i <= end; i++) {
		right[i - mid - 1] = mas[i];
	}
	right[end - mid].ves = 2147483640;

	int j = 0, i = 0;
	for (int k = start; k <= end; k++) {
		std::cout << left[i].ves << ' ' << right[j].ves << '\n';
		if (left[i].ves <= right[j].ves) {
			mas[k] = left[i];
			i++;
		}
		else {
			mas[k] = right[j];
			j++;
		}
	}
	std::cout << '\n';
	delete[]left;
	delete[]right;
}
*/