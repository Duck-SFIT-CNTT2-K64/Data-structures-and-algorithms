#include <bits/stdc++.h>

using namespace std;

class c1{
    int x1, x2;
    public:
    c1(){}
    c1(int x1, int x2){
        this->x1 = x1;
        this->x2 = x2;
    }
    void nhap(){
        cout << "Nhap x1: "; cin >> x1;
        cout << "Nhap x2: "; cin >> x2;
    }
    void xuat(){
        cout << x1 << " " << x2 << endl;
    }
    c1 operator+ (c1 obj2){
        c1 t;
        t.x1 = this->x1 + obj2.x1;
        t.x2 = this->x2 + obj2.x2;
        return t;
    }
    c1 operator- (c1 obj3){
        c1 t1;
        t1.x1 = this->x1 - obj3.x1;
        t1.x2 = this->x2 - obj3.x2;
        return t1;
    }
    c1 operator-(){
        c1 t;
        t.x1 = - this->x1;
        t.x2 = - this->x2;
        return t;
    }
};

int main(){
    c1 a, b, c, d;
    a.nhap();
    b.nhap();
    a.xuat();
    b.xuat();
    c = a + b;
    c.xuat();
    d = a - b;
    d.xuat();
    a = -a;
    a.xuat();
}