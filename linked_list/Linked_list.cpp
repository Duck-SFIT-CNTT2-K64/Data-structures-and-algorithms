#include <bits/stdc++.h>

using namespace std;

template<typename T>

class node{
private:
    T elem;
    node *next;
public:
    node(T e = T(), node* n = NULL){
        elem = e;
        next = n;
    }
    T& getElem(){
        return elem;
    }
    node<T>*& getNext(){
        return next;
    }
    void setElem(T val){
        elem = val;
    }
    void setNext(node<T>* n){
        next = n;
    }
};

template<typename T>
class s_list{
private:
    node *header, *tail;
    int len;
public:
    s_list() : head(NULL), tail(NULL), len(0){}
    class iterator{

    };
    int size(){
        return len;
    }
    bool empty(){
        if(len == 0) return 1;
        else return 0;
    }
    //front(), back() -> gia tri dau, gia tri cuoi
    T& front(){
        return head->getElem();
    }
    T& back(){
        return tail->getElem();
    }
    void push_back(T val){
        head = new node<T>(val, head);
        // tail
        // 0 phan tu -> 1
        len++;
        if(len == 1) tail = head;
    }
    void push_back(T val){
        if(len == 0) push_back(val);
        else{
            tail->setNext(new node<T>(val ,NULL));
            tail = tail->getNext();
            ++len;
        }
    }
    void pop_front(){
        if(num == 0) return;
        if(num == 1) return 
        else{
            head = head->getNext();
        }
        --len;
    }
    void pop_back(){
        if (num == 0) return;
        if (len == 1) head = tail = NULL;
        else{
            node<T>* p = head;
            while(p->getNext() != tail) p = p->getNext();
            p->setNext(NULL);
            tail = p;
        }
        --len;
    }
};

int main(){
    ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
}