#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Queue{
    int size, space, f, l;
    T* elem;
public:
    Queue(){
        size = space = f = l = 0;
        elem = NULL;
    }
    ~Queue(){
        if(elem != NULL) delete[] elem;
    }
    Queue<T>& operator=(Queue<T>& B){
        this->size = B.size;
        this->space = B.space;
        this->f = B.f;
        this->l = B.l;
        T* tmp = new T[space];
        for(int i = 0; i < space; i++){
            tmp[i] = B.elem[i];
        }
        if(elem != NULL) delete[] elem;
        elem = tmp;
        return *this;
    }
    Queue(Queue<T>& B){
        *this = B;
    }
    bool emtpy(){
        return size == 0;
    }
    int get_size(){
        return size; 
    }
    T& front(){
        return elem[f];
    }
    T& back(){
        if(l == 0){
            return elem[space - 1];
        }
        else{
            return elem[l - 1];
        }
    }
    void push(T val){
        if(size == space){
            space = space == 0 ? 1 : space * 2;
            T* tmp = new T[space];
            for(int i = 0, j = f; i < size; i++, j++){
                tmp[i] = elem[j % size];
            }
            if(elem != NULL) delete[] elem;
            elem = tmp;
            f = 0;
            l = size;
        }
        elem[l] = val;
        size++;
        l = (l + 1) % space;
    }
    void pop(){
        if(size == 0) return;
        f = (f + 1) % space;
        size--;
    }
};

int main(){
    //ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
    Queue<int> q;
    q.push(2); q.push(6);
    while(!q.emtpy()){
        cout << q.front() << " ";
        q.pop();
    }
}