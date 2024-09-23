#ifndef __VECTOR__
#define __VECTOR__

#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Vector{
private:
    T* elements;
    int size;
    int space;
public:
    class iterator{
    private:
        T* curr;
    public:
        iterator(T* p = NULL){
            curr = p;
        }
        iterator& operator++(int /* dung int de dung it++ */) {
            curr++; // chuyen con tro toi o nho tiep theo
            return *this;
        }
        iterator& operator--(int){
            curr--;
            return *this;
        }
        iterator operator+(int i){
            return curr + i;
        }
        iterator operator=(iterator itdung){
            curr = itdung.curr;
            return *this;
        }
        bool operator==(iterator itdung){
            return curr == itdung.curr;
        }
        bool operator!=(iterator itdung){
            return !(itdung == (*this));
        }
        T operator*(){
            //vector<int>::iterator it;
            //*it (giá trị tại vị trí it đang trỏ đến)
            return *curr;
        }
    };
    iterator begin(){
        return iterator(elements);
    }
    iterator end(){
        return iterator(elements + size);
    }
    iterator& rbegin(){
        return elements + size - 1;
    }
    iterator& rend(){
        return elements - 1;
    }
    Vector(){
        size = 0;
        space = 0;
    }
    Vector(int n){
        this->size = n;
        this->space = n;
        elements = new T[n];
        for(int i = 0; i < n; i++){
            elements[i] = T();
        }
    }
    Vector(int n, T value){
        this->size = n;
        this->space = n;
        elements = new T[n];
        for(int i = 0; i < n; i++){
            elements[i] = value;
        }
    }
    void reserve(int newmalloc){
        if(space >= newmalloc) return;
        space = newmalloc;
        T* temp = new T[newmalloc];
        for(int i = 0; i < size; i++){
            temp[i] = elements[i];
        }
        if(elements != NULL) delete[] elements;
        elements = temp;
    }
    void push_back(T& value){
        if(space == size){
            reserve(space * 2);
            size++;
            elements[size - 1] = value;
        }
    else{
        size++;
        elements[size - 1] = value;
        }
    }
    void pop_back(){
        if(size == 0){
            return;
        }
        size--; // 
    }
    //v[0]
    T& operator[](int i){
        
    }
    void insert(iterator it, T val){
        if(size == space){
            reserve(size * 2);
        }
        for(iterator it1 = rbegin(); it1 != it - 1; it1--){
            *it1 = *(it1 - 1);
        }
        *it = val;
    }
};

int main(){
    vector<int> A(5, 3);
    vector<int>::iterator it;
    for(it = A.begin(); it != A.end(); it++){
        cout << *it << " ";
    }
}
#endif