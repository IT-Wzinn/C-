#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> st;
    stack<int> st2; // Tạo thêm stack thứ 2 để demo lệnh swap

    // 1. push(): Thêm phần tử vào đỉnh
    st.push(10);
    st.push(20);

    // 2. emplace(): Thêm phần tử vào đỉnh (tối ưu hơn push do khởi tạo trực tiếp)
    st.emplace(30); // Stack hiện tại: 10 -> 20 -> 30 (Đỉnh)

    // 3. top(): Lấy giá trị phần tử ở đỉnh (không xóa)
    cout << "Phan tu o dinh stack: " << st.top() << endl; // In ra 30

    // 4. pop(): Xóa phần tử ở đỉnh
    st.pop(); 
    
    // 5. size(): Trả về số lượng phần tử
    cout << "Kich thuoc stack sau khi pop: " << st.size() << endl; // In ra 2 (còn 10 và 20)

    // 6. swap(): Hoán đổi nội dung 2 stack cho nhau
    st2.push(99);
    st.swap(st2); // Lúc này st chứa [99], st2 chứa [10, 20]

    // 7. empty(): Kiểm tra stack có rỗng không (trả về true/false)
    // Duyệt và in ra toàn bộ st2 (phải pop dần ra vì stack không cho truy cập bằng chỉ số)
    cout << "Cac phan tu con lai trong st2: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    
//======================================================================================================================================================
    queue<int> q;

    // Thêm phần tử vào cuối hàng
    q.push(1);
    q.push(2);
    q.push(3); // Queue hiện tại: 1 (Đầu) -> 2 -> 3 (Cuối)

    cout << "Phan tu o dau queue: " << q.front() << endl; // In ra 1
    cout << "Phan tu o cuoi queue: " << q.back() << endl; // In ra 3

    // Xóa phần tử ở đầu hàng
    q.pop(); 

    // Duyệt queue
    cout << "Cac phan tu con lai: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}