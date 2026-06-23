#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {

    // ==========================================
    // 2. HASH MAPS (Bảng băm - unordered_map)
    // ==========================================
    cout << "--- HASH MAPS ---\n";
    unordered_map<string, int> map;

    // Thêm/Cập nhật (Insert/Update): O(1) trung bình
    map["apple"] = 5; 
    map.insert({"mango", 15});
    map.emplace("orange", 20); // Tương tự insert nhưng tối ưu hiệu năng hơn

    // Kiểm tra tồn tại (Lookup)
    // Cách 1: Dùng count() - Trả về 1 nếu có, 0 nếu không
    if (map.count("apple")) {
        // Xóa (Erase)
        map.erase("apple"); 
    }
    
    // Cách 2: Dùng find() - Chuẩn xác và nhanh hơn nếu cần lấy luôn giá trị ra dùng
    auto it = map.find("mango");
    if (it != map.end()) {
        cout << "Tim thay mango voi gia tri: " << it->second << "\n";
    }
    
    map["banana"] = 10;
    
    // Xem kích thước
    cout << "So luong cap key-value trong map: " << map.size() << "\n";

    // Duyệt (Iterate)
    cout << "Cac phan tu trong map:\n";
    for (auto& pair : map) {
        cout << "- " << pair.first << ": " << pair.second << "\n";
    }

    // Làm rỗng map
    map.clear();
    if (map.empty()) cout << "Map da rong!\n";

    return 0;
}