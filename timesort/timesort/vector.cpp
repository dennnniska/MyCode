#include "vector.h"
#include <iostream>

bool vector::isEmpty() {
	return size_ == 0;
}

size_t vector::size() {
	return size_;
}

size_t vector::capacity() {
	return capacity_;
}

void vector::add_memory() {
	capacity_ *= 2;
	int* tmp = arr_;
	arr_ = new int[capacity_];
	for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
	delete[] tmp;
}

void vector::push_back(int value) {
	if (size_ >= capacity_) add_memory();
	arr_[size_++] = value;
}


void vector::remove(size_t index) {
	for (size_t i = index + 1; i < size_; ++i) {
		arr_[i - 1] = arr_[i];
	}
	--size_;
}


vector::~vector() {
	delete[] arr_;
}

int& vector::operator[](size_t index) {
	return arr_[index];
}

vector::vector(vector& other) {
	if (this != &other) {
		delete[] arr_;
		arr_ = new int[other.capacity_];
		for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
		size_ = other.size_;
		capacity_ = other.capacity_;
	}
}



