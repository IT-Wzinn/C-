#include <iostream>
#include <forward_list> // Bắt buộc phải khai báo thư viện này nếu muốn sài sẵn thư viện STL
using namespace std;

// Tạo Likedlist bằng Struct thủ công 
struct Node {
    int data;
    Node *next;
    
    // Contructer 1
    Node(int x) : data(x), next(nullptr) {}

    // Contructer 2
    Node(int x, Node *nextNode) : data(x), next(nextNode) {}
};

// Thêm vào đầu  
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Thêm vào cuối (Insert at Tail) [cite: 330]
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) { // Duyệt đến cuối danh sách 
        curr = curr->next;
    }
    curr->next = newNode;
}

// Xóa một Node có giá trị X bất kỳ ở giữa [cite: 333]
void deleteNode(Node*& head, int key) {
    if (!head) return;
    
    // Xóa Node ở đầu [cite: 331]
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != key) {
        curr = curr->next;
    }
    
    // Nếu tìm thấy, thực hiện cắt dây để bỏ qua Node đó
    if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

int main(){
    
    Node* node1 = new Node{10, nullptr};
    Node* node2 = new Node{20, nullptr};
    Node* node3 = new Node{30, nullptr};

    node1->next = node2;
    node2->next = node3;

    // Head giữ node đầu tiên
    Node* head = node1;

    // Duyệt từ head
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // 1. Khởi tạo danh sách liên kết đơn
    forward_list<int> myList = {20, 30, 40};

    // 2. Thêm phần tử (Chỉ có thể thêm nhanh vào ĐẦU danh sách)
    // Độ phức tạp: O(1)
    myList.push_front(10); // Danh sách hiện tại: 10 -> 20 -> 30 -> 40

    // 3. Chèn phần tử vào GIỮA (Phải dùng iterator)
    auto it = myList.begin(); // Con trỏ đang trỏ vào 10
    ++it;                     // Nhích con trỏ lên 1 bước (trỏ vào 20)
    myList.insert_after(it, 25); // Chèn 25 vào SAU số 20
    // Danh sách: 10 -> 20 -> 25 -> 30 -> 40

    // 4. Xóa phần tử
    myList.pop_front();       // Xóa phần tử ở đầu (xóa số 10)
    myList.remove(30);        // Xóa TẤT CẢ các Node có giá trị là 30

    // 5. Duyệt danh sách (Read / Traverse)
    cout << "Danh sách hiện tại: ";
    for (int data : myList) {
        cout << data << " -> ";
    }
    cout << "nullptr\n";

    return 0;
}