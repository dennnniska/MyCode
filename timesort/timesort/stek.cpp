#include "stek.h"
#include <iostream>

stack::stack() {
    size = 0;
    head = nullptr;
}

stack::~stack() {
    if (head != nullptr) {
        Node* next = head->pNext;
        while (next != nullptr) {
            delete head;
            head = next;
            next = head->pNext;
        }
        delete head;
    }
}

void stack::pop() {
    if (head == nullptr) {
        std::cout << "Error";
        return;
    }
    Node* cur = head;
    head = head->pNext;
    delete cur;
    size--;
}

void stack::push(int values, int size) {
    if (head == nullptr) {
        head = new Node(values, size);
        this->size++;
        return;
    }
    Node* cur = head;
    head = new Node(values, size);
    this->size++;
    head->pNext = cur;
}

bool stack::emply() {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int stack::check_data() {
    if(head != nullptr)
        return head->data;
}

int stack::check_size() {
    if (head != nullptr)
        return head->size;
}

int stack::get_size() {
    return size;
}