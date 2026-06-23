#include <iostream>
using namespace std;

// Cấu trúc một Node trong cây
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Thêm (Insert): Dùng đệ quy tìm đúng vị trí lá để gắn Node mới vào (O(log N) trung bình)
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// 2. Tra cứu (Search): Tìm một giá trị xem có tồn tại trong cây không (O(log N) trung bình)
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Hàm phụ trợ: Tìm Node có giá trị nhỏ nhất trên cây (Phục vụ cho thao tác Xóa)
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 3. Xóa (Delete): Xử lý đầy đủ cả 3 trường hợp của BST (O(log N) trung bình)
TreeNode* deleteBST(TreeNode* root, int val) {
    if (!root) return root;

    // Bước 1: Tìm Node cần xóa
    if (val < root->val) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->val) {
        root->right = deleteBST(root->right, val);
    } else {
        // Đã tìm thấy Node cần xóa (val == root->val)

        // THƯỜNG HỢP 1 & 2: Node lá (không con) hoặc Node chỉ có 1 con
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // TRƯỜNG HỢP 3: Node có đầy đủ 2 con
        // Tìm Node nhỏ nhất bên cây con phải (In-order Successor) để thế mạng
        TreeNode* temp = findMin(root->right);
        root->val = temp->val; // Ghi đè giá trị của Node thế mạng lên Node cần xóa
        
        // Xóa Node thế mạng thực sự ở cây con bên phải
        root->right = deleteBST(root->right, temp->val);
    }
    return root;
}

// 4. Duyệt cây (Traversal): Duyệt theo thứ tự giữa (In-order) sẽ in ra các phần tử tăng dần
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Demo Thêm phần tử
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);

    cout << "Cay BST ban dau (In-order): ";
    inorder(root); // In ra: 20 30 40 50 60 70 80
    cout << "\n";

    // Demo Tra cứu
    int key = 60;
    if (searchBST(root, key)) cout << "Tim thay " << key << " trong cay.\n";
    else cout << "Khong tim thay " << key << ".\n";

    // Demo Xóa phần tử (Trường hợp xóa Node có 2 con là số 50)
    root = deleteBST(root, 50);
    cout << "Cay BST sau khi xoa nut 50: ";
    inorder(root); // In ra: 20 30 40 60 70 80
    cout << "\n";

    return 0;
}