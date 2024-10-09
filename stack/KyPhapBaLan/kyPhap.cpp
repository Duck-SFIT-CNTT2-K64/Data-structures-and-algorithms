#include<bits/stdc++.h>
using namespace std;

map<char, int> doUuTien = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}};

int tinhToan(int a, int b, char toanTu) {
    if (toanTu == '+') return a + b;
    if (toanTu == '-') return a - b;
    if (toanTu == '*') return a * b;
    if (toanTu == '/') return a / b;
    return 0;
}

string chuyenTrungToSangHauTo(const string& bieuThuc) {
    stack<char> nganXep;
    string hauTo = "";
    
    for (char kyTu : bieuThuc) {
        if (isdigit(kyTu)) {
            hauTo += kyTu;
        } else if (kyTu == '(') {
            nganXep.push(kyTu);
        } else if (kyTu == ')') {
            while (!nganXep.empty() && nganXep.top() != '(') {
                hauTo += nganXep.top();
                nganXep.pop();
            }
            nganXep.pop();
        } else if (doUuTien.find(kyTu) != doUuTien.end()) {
            while (!nganXep.empty() && doUuTien[nganXep.top()] >= doUuTien[kyTu]) {
                hauTo += nganXep.top();
                nganXep.pop();
            }
            nganXep.push(kyTu);
        }
    }

    while (!nganXep.empty()) {
        hauTo += nganXep.top();
        nganXep.pop();
    }
    
    return hauTo;
}

int tinhGiaTriHauTo(const string& hauTo) {
    stack<int> stackSo;
    
    for (char kyTu : hauTo) {
        if (isdigit(kyTu)) {
            stackSo.push(kyTu - '0');
        } else {
            int toanHang2 = stackSo.top(); stackSo.pop();
            int toanHang1 = stackSo.top(); stackSo.pop();
            int ketQua = tinhToan(toanHang1, toanHang2, kyTu);
            stackSo.push(ketQua);
        }
    }
    
    return stackSo.top();
}

int main() {
    string bieuThuc;
    getline(cin, bieuThuc);
    string hauTo = chuyenTrungToSangHauTo(bieuThuc);
    cout << hauTo << "\n";
    int ketQua = tinhGiaTriHauTo(hauTo);
    cout << ketQua << "\n";

    return 0;
}
