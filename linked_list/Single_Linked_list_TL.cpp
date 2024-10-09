#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Node{
public:
    T data;
    Node *next;
    Node(T value){
        data = value;
        next = nullptr;
    }
};

template<typename T>

class SingleLinkedList{
    Node<T> *head;
    Node<T> *trail;
    int num = 0;
public:
    SingleLinkedList() : head(0), trail(0), num(0) {}
    int size(){ return num; }
    bool empty(){ return num == 0; }
    Node<T> *back(){ return trail; }
    Node<T> *front(){return head; }
    void push_back(Node<T> *newNode){
        if(empty()){
            head = trail = newNode;
        }
        else{
            trail->next = newNode;
            trail = newNode;
        }
        ++num;
    }
    void push_front(Node<T> *newNode){
        if(empty()){
            head = trail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        ++num;
    }
    void insert(int pos, Node<T> *newNode){
        if(pos < 0 || pos > num){
            return;
        }
        if(pos == 0){
            push_front(newNode);
        }
        else if(pos == num){
            push_back(newNode);
        }
        else{
            Node<T> *tmp = head;
            for(int i = 1; i < pos; i++){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            ++num;
        }
    }
    void pop_front(){
        if(empty()) return;
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
        --num;
        if(num == 0) trail = nullptr;
    }
    void pop_back(){
        if(empty()) return;
        if(head == trail){
            delete head;
            head = trail = nullptr;
        }
        else{
            Node<T> *tmp = head;
            while(tmp->next != trail){
                tmp = tmp->next;
            }
            delete trail;
            trail = tmp;
            trail->next = nullptr;
        }
        --num;
    }
    void erase(int pos){
        if(pos < 0 || pos > num){
            return;
        }
        if(pos == 0){
            pop_front();
        }
        else if(pos == num - 1){
            pop_back();
        }
        else{
            Node<T> *tmp = head;
            for(int i = 1; i < pos; i++){
                tmp = tmp->next;
            }
            Node<T> *eraseNode = tmp->next;
            tmp->next = eraseNode->next;
            delete eraseNode;
            --num;
        }
    }
    class iterator{
        Node<T> *node;
    public:
        iterator(Node<T> *n) : node(n){}
        bool operator!=(const iterator &other){
            return node != other.node;
        }
        // ++tiento
        iterator &operator++(){
            node = node->next;
            return *this;
        }
        //hauto++
        iterator operator++(int){
            iterator tmp = *this;
            node = node->next;
            return tmp; 
        }
        T &operator*(){
            return node->data;
        }
    };
    iterator begin() {return iterator(head);}
    iterator end() {return iterator(nullptr);}
};

int main(){
    SingleLinkedList<int> ls;
    Node<int> *newNode = new Node<int>(10);
    ls.push_back(newNode);
    for(auto it = ls.begin(); it != ls.end(); it++){
        cout << *it << " ";
    }
    return 0;
}