#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
template<typename T>
class List{
private:
    class Node{
    public:
        Node *pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr){
            this->data = data;
            this-> pNext = pNext;
        }
    };
    int size;
    Node *head;
public:
    List();
    ~List();
    void push_back(T values = T());
    void delete_List();
    int Getsize(){return size;}
    T get(int index = 0);
    void push(int index = 0, T values = T());
    void pop(int index = 0);
};
template<typename T>
List<T>::List(){
    size = 0;
    head = nullptr;
}
template<typename T>
List<T>::~List(){
    if(head != nullptr){
        Node *next = head->pNext;
        while(next != nullptr){
            delete head;
            head = next;
            next = head->pNext;
        }
        delete head;
    }
}
template<class T>
void List<T>::delete_List(){
    if(head != nullptr){
        Node *cur;
        while(head != NULL){
            cur = head->pNext;
            delete head;
            head = cur;
        }
    }
    size = 0;
}
template<class T>
T List<T>::get(int index){
    Node *cur = head;
    while(index--){
        cur = cur->pNext;
    }
    return cur->data;
}
template<class T>
void List<T>:: push_back(T values){
    size++;
    if(head == nullptr){
        head = new Node(values);
    }
    else{
        Node *cur = this->head;
        while(cur->pNext != nullptr){
            cur = cur->pNext;
        }
        cur->pNext = new Node(values);
    }
}
template<class T>
void List<T>::push(int index, T values){
    Node *cur = head;
    if (index >= size){
        cout << "Error";
        return;
    }
    if(index == 0){
        cur->pNext = head;
        head = cur;
        return;
    }
    for(int i = 0; i < index - 1; i++){
        cur = cur->pNext;
    }
    Node next = cur->pNext;
    cur->pNext = new Node(values);
    cur->pNext->pNext = next;
}
template<class T>
void List<T>:: pop(int index){
    if(index >= size){
        cout << "Error";
        return;
    }
    Node *cur = head;
    if(index == 0){
        head = head->pNext;
        delete cur;
        return;
    }
    for(int i = 0; i < index - 1; i++){
        cur = cur->pNext;
    }
    Node next = cur->pNext;
    next = cur->pNext;
    delete cur->pNext;
    cur->pNext = next;
}
int main(){
    return 0;
}
