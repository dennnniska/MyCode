#pragma once
#include <iostream>
class vector {
public:
    vector() {
        arr_ = new int[1];
        capacity_ = 1;
    }
    bool isEmpty();
    size_t size();
    size_t capacity();
    void add_memory();
    void push_back(int value);
    void remove(size_t index);
    ~vector();
    int& operator[](size_t index);
    vector(vector& other);
    vector& operator=(vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = new int[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

private:
    int* arr_;
    size_t size_{};
    size_t capacity_{};

};