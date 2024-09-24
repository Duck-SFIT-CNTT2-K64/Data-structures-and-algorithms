#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (empty()) return;
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void pop_back() {
        if (empty()) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    bool empty() const {
        return size == 0;
    }

    int get_size() const {
        return size;
    }

    void print_forward() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void print_backward() const {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoubleLinkedList<int> list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    
    std::cout << "Forward: ";
    list.print_forward();
    
    std::cout << "Backward: ";
    list.print_backward();
    
    list.pop_front();
    list.pop_back();
    
    std::cout << "After popping front and back: ";
    list.print_forward();
    
    return 0;
}