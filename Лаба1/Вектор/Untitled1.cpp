#include<iostream>
using namespace std;
template<typename T>
class vector{
private:
    int rate;
    int size;
public:
    T *List;
    vector(int sizee = 0);
    ~vector();
    void push(int index = 0, T values = T());
    int getsize(){return size;}
    void pop(int index = 0);
};

template<typename T>
vector<T>::vector(int sizee){
    rate = sizee;
    size = sizee;
    if(size != 0){
        List = new T[size];
    }
}

template<typename T>
vector<T>::~vector(){
    if(rate != 0)
        delete []List;
}

template<typename T>
void vector<T>::push(int index, T values){
    size++;
    if(index > size || index < 0){

        cout << "Error";
        size--;
        return;
    }
    if(size > rate){
        T *newList;
        rate = (rate*3+2)/2;
        newList = new T[rate];
        for(int i = 0; i < index; i++){
            newList[i] = List[i];
        }
        newList[index] = values;
        for(int i = index; i < size - 1; i++){
            newList[i+1] = List[i];
        }
            delete []List;
        List = newList;
    }
    else{
        for(int i = size - 1; i > index; i--){
            List[i] = List[i-1];
        }
        List[index] = values;
    }
}

template<typename T>
void vector<T>::pop(int index){
    if(index >= size || index < 0){
        cout << "Error";
        return;
    }
    for(int i = index; i < size - 1; i++){
        List[i] = List[i+1];
    }
    size--;
}
int main(){
    vector<int> b(4);
    for(int i = 0; i < b.getsize(); i++){
        b.List[i] = i;
    }
    b.push(10);
    b.pop(10);
    b.push(4);
    b.pop(0);
    for(int i = 0; i < b.getsize(); i++){
        cout << b.List[i] << ' ';
    }
    return 0;
}
