#include "queue.h"
void queue::pop() {
	start++;
	if (start == size) {
		start = 0;
	}
}
void queue::push(int index) {
	mas[end] = index;
	end++;
	if (end == size) {
		end = 0;
	}
	if (end == start) {
		int* new_map;
		new_map = new int[size + 10];
		for (int i = start; i < size; i++) {
			new_map[i - start] = mas[i];
		}
		for (int i = 0; i < start; i++) {
			new_map[size + i] = mas[i];
		}
		delete[]mas;
		mas = new_map;
		start = 0;
		end = size;
		size += 10;
	}
}
int queue::front() {
	if (start != end) {
		return mas[start];
	}
	return 0;
}
queue::queue() {
	size = 50;
	mas = new int[size];
	start = 0;
	end = 0;
}
queue::~queue() {
	if (mas != nullptr) {
		delete[] mas;
	}
}

bool queue::size_() {
	return end - start;
}