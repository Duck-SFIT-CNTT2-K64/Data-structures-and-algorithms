#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Vector{
    int size, space;
    T* a;
public:
    // Contructor - Ham tao
    Vector() : space(2), size(0){
        a = new T[space];
    }
    // Destructor - Ham huy
    ~Vector(){
        delete[] a;
    }
    // Add the element to the end of the vector
    void push_back(T value){
        if(size == space){
            space *= 2;
            T* tmp = new T[space];
            for(int i = 0; i < size; i++){
                tmp[i] = a[i];
            }
            delete[] a;
            a = tmp;
        }
        a[size++] = value;
    }
    // Get the current size of the vector
    int get_size(){
        return size;
    }
    // Access elements via index
    T& operator[] (int index){
        if(index >= size || index < 0){
            throw out_of_range("Index out of the range");
        }
    }
    class Iterator{
        T* ptr; // con tro den phan tu hien tai
    public:
        // Contructor
        Iterator(T* ptr) : ptr(ptr){}

        T& operator* (){
            return *ptr;
        }
        // tiền tố <-> ++it
        Iterator& operator++ (){
            ptr++;
            return *this;
        }
        // hậu tố <-> it++
        Iterator& operator++ (int){
            Iterator temp = *this;
            ptr++;
            return temp;
        }
        bool operator==(Iterator other){
            return ptr == other.ptr;
        }
        bool operator!=(Iterator other){
            return ptr != other.ptr;
        }
    };
    Iterator begin(){
        return Iterator(a);
    }
    Iterator end(){
        return Iterator(a + size);
    }
    Iterator rbegin(){
        return a + size - 1;
    }
    Iterator rend(){
        return a - 1;
    }
};

int main(){
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    for(Vector<int>::Iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    return 0;
}