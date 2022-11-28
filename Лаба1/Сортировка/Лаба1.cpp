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
template<class T>
class stack
{
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
    void pop();
    void push(T values = T());
    bool emply();
    T check();
    stack();
    ~stack();
};
template<typename T>
stack<T>::stack(){
    size = 0;
    head = nullptr;
}
template<typename T>
stack<T>::~stack(){
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
void stack<T>::pop(){
    if(head == nullptr){
        cout << "Error";
        return;
    }
    Node *cur = head;
    head = head->pNext;
    delete cur;
}
template<class T>
void stack<T>::push(T values){
    if(head == nullptr){
        head = new Node(values);
        return;
    }
    Node*cur = head;
    head = new Node(values);
    head->pNext = cur;
}
template<class T>
bool stack<T>::emply(){
    if(head == nullptr){
        return true;
    }
    else{
        return false;
    }
}
template<class T>
T stack<T>::check(){
    return head->data;
}

int main(){
    setlocale(0, "");
    string s;
    cout << "¬ведите выражение:" << endl;
    cin >> s;
    stack<string> operation;
    int p = 0;
    for(int i = 0; i < s.size();i++){
        if(s[i] == '('){
            p++;
           }
        if(s[i] == ')'){
            p--;
        }
        if(p < 0){
            cout << "Error()";
        }
    }
    if(p != 0){
        cout << "Error()";
    }
    string ans = "";
    string prov;
    for(int i = 0; i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans += s[i];
        }
        else{
        if(s[i] != ')' && s[i] != '(' && s[i]!= 'c' && s[i]!='s'){
            ans += ',';
        }
        if(s[i] == 'c' || s[i] == 's'){
                prov = s[i];
                prov += s[i+1];
                prov += s[i+2];
                i += 3;
                operation.push(prov);
            }
        if(operation.emply()){
            prov = s[i];
            operation.push(prov);
        }
        else{
            if(s[i] == '('){
                prov = s[i];
            operation.push(prov);
               }
            if(s[i] == ')'){
                prov = operation.check();
                while (prov != "("){
                    ans+=prov;
                    operation.pop();
                    prov = operation.check();
                }
                operation.pop();
                if(!operation.emply()){
                    if(operation.check() == "sin" || operation.check() == "cos"){
                        ans += operation.check();
                        operation.pop();
                    }
                }
            }
            if(s[i] == '+' || s[i] == '-'){
                prov = operation.check();
                while (prov != "(" && !operation.emply()){
                    prov = operation.check();
                    ans+=prov;
                    operation.pop();
                }
                prov = s[i];
            operation.push(prov);
            }
            if(s[i] == '*' || s[i] == '/'){
                prov = operation.check();
                while (prov != "(" && !operation.emply() && prov != "+" && prov != "-"){
                    prov = operation.check();
                    ans+=prov;
                    operation.pop();
                }
                prov = s[i];
            operation.push(prov);
            }
            if(s[i] == '^'){
                prov = s[i];
            operation.push(prov);
            }

        }
        }
    }
    while(!operation.emply()){
        prov = operation.check();
        ans += prov;
        operation.pop();
    }
    cout << ans;
    return 0;
}
