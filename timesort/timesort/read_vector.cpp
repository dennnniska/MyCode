#include <iostream>
#include "read_vector.h"
void read_vector::reader() {
	size = 0;
	while (size < 1) {
		std::cout << "Enter size array: ";
		std::cin >> size;
	}
	std::cout << "Enter array : ";
	int x;
	for (int i = 0; i < size; i++) {
		std::cin >> x;
		arr.push_back(x);
	}
}

vector& read_vector::get_arr() {
	return arr;
}

int read_vector:: get_size() {
	return size;
}