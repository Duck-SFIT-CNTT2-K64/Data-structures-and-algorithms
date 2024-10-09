#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct Node {
    int value;                 // Giá trị của nút
    vector<Node*> children;    // Danh sách các con của nút

    // Constructor
    Node(int val) : value(val) {}
};

// Hàm sinh cây từ số nguyên dương n
Node* generateTree(int n) {
    Node* root = new Node(n);   // Tạo nút gốc với giá trị n
    vector<Node*> queue = {root};   // Sử dụng một hàng đợi để duyệt cây
    for (size_t i = 0; i < queue.size(); i++) {
        Node* current = queue[i];  // Lấy nút hiện tại từ hàng đợi
        bool hasChildren = false;  // Kiểm tra xem nút có sinh ra con không
        for (int a = 1; a * a <= current->value; a++) {
            if (current->value % a == 0) {
                int b = current->value / a;  // Tìm cặp (a, b) thỏa mãn
                if (a < b) {
                    int m = (a - 1) * (b + 1);  // Tính giá trị m mới
                    if (m > 0) {
                        Node* child = new Node(m);  // Tạo nút con
                        current->children.push_back(child);  // Thêm vào danh sách con
                        queue.push_back(child);  // Thêm nút con vào hàng đợi
                        hasChildren = true;
                    }
                }
            }
        }
        if (!hasChildren) {
            current->children.push_back(new Node(0));  // Nếu không có con, tạo nút có giá trị 0
        }
    }
    return root;  // Trả về nút gốc của cây
}

// Hàm duyệt cây theo Preorder (Tiền thứ tự)
void preorder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->value);  // Thêm giá trị của nút vào kết quả
    for (Node* child : node->children) {
        preorder(child, result);    // Duyệt tiếp các con theo Preorder
    }
}

// Hàm duyệt cây theo Inorder (Trung thứ tự)
void inorder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    if (node->children.empty() || node->children[0]->value == 0) {
        result.push_back(0);  // Thêm giá trị 0 nếu không có con
        result.push_back(node->value);
    } else {
        inorder(node->children[0], result);  // Duyệt con trái nhất
        result.push_back(node->value);       // Thêm giá trị của gốc
        for (size_t i = 1; i < node->children.size(); i++) {
            inorder(node->children[i], result);  // Duyệt các con còn lại
        }
    }
}

// Hàm duyệt cây theo Postorder (Hậu thứ tự)
void postorder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    for (Node* child : node->children) {
        postorder(child, result);   // Duyệt lần lượt các con theo Postorder
    }
    result.push_back(node->value);  // Thêm giá trị của gốc
}

// Hàm giải phóng bộ nhớ của cây
void deleteTree(Node* root) {
    if (root == nullptr) return;
    for (Node* child : root->children) {
        deleteTree(child);  // Giải phóng bộ nhớ của các con
    }
    delete root;  // Giải phóng bộ nhớ của gốc
}

// Hàm in kết quả của các lần duyệt cây
void printTraversal(const vector<int>& traversal) {
    for (int val : traversal) {
        cout << val << " ";  // In ra các giá trị theo thứ tự duyệt
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;  // Đọc số nguyên dương n từ người dùng

    Node* root = generateTree(n);  // Sinh cây từ số n

    vector<int> preorderResult, inorderResult, postorderResult;
    preorder(root, preorderResult);  // Duyệt cây theo Preorder
    inorder(root, inorderResult);    // Duyệt cây theo Inorder
    postorder(root, postorderResult); // Duyệt cây theo Postorder

    // In kết quả của từng loại duyệt
    printTraversal(preorderResult);  // In kết quả Preorder
    printTraversal(inorderResult);   // In kết quả Inorder
    printTraversal(postorderResult); // In kết quả Postorder

    deleteTree(root);  // Giải phóng bộ nhớ
    return 0;
}
