#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Stack{
    int size, space;
    T* arr;
public:
    Stack() : size(0), space(0), arr(NULL) {}
    ~Stack(){
        delete[] arr;
    }

    // Hàm lấy kích thước hiện tại stack
    int get_size(){
        return size;
    }

    // Hàm kiểm tra xem stack có rỗng hay không
    bool empty(){
        return size == 0;
    }

    // Hàm trả về phần tử ở đỉnh stack
    T& top(){
        if(empty()){
            throw out_of_range("Stack is empty!");
        }
        return arr[size - 1];
    }

    // Hàm xóa phần tử trên đỉnh stack
    void pop(){
        if(empty()){
            throw out_of_range("Stack is empty, can't pop!");
        }
        size--;
    }
    void push(T value){
        if(size == space){
            space = size == 0 ? 1 : space * 2;
            T* temp = new T[space];
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }
            if(arr != NULL) delete[] arr;
            arr = temp;
        }
        arr[size] = value;
        ++size;
    }
    void clear(){
        size = 0;
    }
};

int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(40);
    cout << s.top() << endl;

    cout << s.get_size() << endl;

    if(s.empty()) cout << "Khong co phan tu nao" << endl;
    else cout << "Dang co nhieu phan tu" << endl;
}