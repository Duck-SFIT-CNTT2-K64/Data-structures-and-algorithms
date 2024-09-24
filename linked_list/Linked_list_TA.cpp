#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
template<typename T>
class node {
private:
    T elem;
    node* next;
    node* prev;
public:
    node(T e = T(), node* n = NULL) {
        elem = e;
        next = n;
    }
    T& getElem() {
        return elem;
    }
    node<T>*& getNext() {
        return next;
    }
    void setElem(T val) {
        elem = val;
    }
    void setNext(node<T>* n) {
        next = n;
    }
};
template<typename T>
class s_list {
private:
    node<T> *head, *tail;
    int len;
public:
    s_list(): head(NULL), tail(NULL), len(0) {}
    class iterator {
    private:
        node<T> *curr;
	public:
		iterator(node<T> *p = NULL): curr(p) {}
		node<T>* getCurr(){
			return curr;
		}
		iterator& operator=(iterator& p) {
			this->curr = p.getCurr();
			return *this;
		}
		bool operator!=(iterator p) {
			return curr!=p.getCurr();
		}
		iterator operator++() {
			curr=curr->getNext();
			return curr;
		}
		iterator operator++(int) {
			node<T> *temp = curr;
			curr = curr->getNext();
			return temp;
		}
		T& operator*() { 
            return curr->getElem();
		}
    };
    iterator begin() {return head;}
    iterator end() {return NULL;}
    //=L.begin()
    int size() {
        return len;
    }
    bool empty() {
        if (len == 0) return 1;
        else return 0;
    }
    //front(), back() -> gtri dau, gtri cuoi
    //L.front() = 3
    T& front() {
        return head->getElem();
    }
    T& back() {
        return tail->getElem();
    }
    void push_front(T val) {
        head = new node<T>(val, head);
        //tail
        //0 phan tu -> 1
        len++;
        if (len == 1) tail = head;
    }
    void push_back(T val) {
        if (len == 0) push_front(val);
        else {
            tail->setNext(new node<T>(val, NULL));
            tail = tail->getNext();
            ++len;
        }
    }
    void pop_front() {
        if (len == 0) return;
        if (len == 1) head = tail = NULL;
        else {
            head = head->getNext();
        }
        --len;
    }
    void pop_back() {
        if (len == 0) return;
        if (len == 1) head = tail = NULL;
        else {
            node<T>* p = head;
            while (p->getNext() != tail) p = p->getNext();
            p->setNext(NULL);
            tail = p;
        }
        --len;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // node n = node(3);
    // node<int>* p = new node<int>(3, NULL);
    // //a = node<int>(3, NULL)
    // //a.getElem();
    // //p->getElem(); (*p).getelem();
    // cout << n.getElem() << ' ' << n.getNext();
    s_list<int> L;
    L.push_back(3);
    L.push_back(1);
    L.push_back(0);
    L.push_back(7);
    L.push_front(0);
    L.pop_front();
    for (s_list<int>::iterator it = L.begin(); it != L.end(); it++) cout << *it << ' ';
    return 0;
}