#pragma once

class stack
{
private:
    class Node {
    public:
        Node* pNext;
        int data;
        int size;
        Node(int data = 0, int size = 0,Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->size = size;
        }
    };
    int size;
    Node* head;
public:
    void pop();
    void push(int values = 0, int size = 0);
    bool emply();
    int get_size();
    int check_data();
    int check_size();
    stack();
    ~stack();
};

