#include "print_array.h"
#include "vector.h"
#include<iostream>
void print_array::print_(vector& array) {
	std::cout << std::endl;
	for (int i = 0; i < array.size(); i++) {
		if (i % 20 == 0)
			std::cout << std::endl;
		std::cout << array[i] << ' ';
	}
}