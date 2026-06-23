#include <iostream>
#include <string>
#include <vector>
#include <memory> // Thư viện cần thiết để dùng smart pointers

using namespace std;

// ========================================================
// 1. TÍNH TRỪU TƯỢNG (Abstraction)
// Lớp NhanVien là một "bản thiết kế" (Abstract Class).
// Nó chứa hàm ảo thuần túy (= 0), che giấu hoàn toàn cách thức hoạt động,
// chỉ đưa ra một "hợp đồng" bắt buộc mọi nhân viên phải có hành động làm việc.
// ========================================================
class NhanVien {
// ========================================================
// 2. TÍNH ĐÓNG GÓI (Encapsulation)
// Thuộc tính 'ten' được khóa lại bằng 'protected'. 
// Không ai từ bên ngoài (hàm main) có thể tự ý sửa tên nhân viên được, 
// nhưng các lớp con (kế thừa) thì vẫn có thể dùng.
// ========================================================
protected:
    string ten;

public:
    NhanVien(string t) : ten(t) {}
    virtual ~NhanVien() {} // Luôn có virtual destructor ở lớp cha

    // Hàm ảo thuần túy (Mấu chốt của tính Trừu tượng)
    virtual void lamViec() const = 0; 
};

// ========================================================
// 3. TÍNH KẾ THỪA (Inheritance)
// Lớp LapTrinhVien kế thừa (: public) từ lớp cha NhanVien.
// Nó tái sử dụng thuộc tính 'ten' mà không cần phải khai báo lại.
// ========================================================
class LapTrinhVien : public NhanVien {
private:
    string ngonNgu; // (Đóng gói) Thuộc tính riêng của Developer

public:
    // (Kế thừa) Gọi constructor lớp cha để nhờ cha khởi tạo biến 'ten'
    LapTrinhVien(string t, string nn) : NhanVien(t), ngonNgu(nn) {}

// ========================================================
// 4. TÍNH ĐA HÌNH (Polymorphism)
// Lớp con ghi đè (override) lại hàm lamViec() của lớp cha.
// Định nghĩa cách làm việc TÙY BIẾN của riêng Lập trình viên.
// ========================================================
    void lamViec() const override {
        cout << "=> [Lap Trinh Vien] " << ten << " dang code bang " << ngonNgu << endl;
    }
};

// Kế thừa một lớp con khác để thấy sự đa dạng
class NhanVienSales : public NhanVien {
private:
    int KPI;

public:
    NhanVienSales(string t, int kpi) : NhanVien(t), KPI(kpi) {}

    // (Đa hình) Cùng là làm việc, nhưng Sales làm việc kiểu khác
    void lamViec() const override {
        cout << "=> [Sales] " << ten << " dang di chot don. KPI: " << KPI << " trieu" << endl;
    }
};

// ========================================================
// PHẦN VẬN HÀNH DƯỚI MAIN
// Nơi Trừu Tượng và Đa Hình hợp kiếm
// ========================================================
int main() {
    cout << "--- HE THONG QUAN LY CONG TY ---" << endl;

    // (Trừu tượng ở Main): Dùng con trỏ thông minh (unique_ptr) lớp cha (NhanVien) 
    // để làm cái "túi" đựng chung mọi loại nhân viên. Che giấu đi việc ai là Dev, ai là Sales.
    vector<std::unique_ptr<NhanVien>> congTy;
    
    // Tạo đối tượng an toàn và cấp phát động bằng std::make_unique
    congTy.push_back(std::make_unique<LapTrinhVien>("Nguyen Van A", "C++"));
    congTy.push_back(std::make_unique<NhanVienSales>("Tran Thi B", 500));
    congTy.push_back(std::make_unique<LapTrinhVien>("Le Van C", "Python"));

    // (Đa hình ở Main): Chỉ cần 1 vòng lặp và 1 lệnh DUY NHẤT.
    // Chương trình sẽ TỰ ĐỘNG nhận diện đối tượng và gọi đúng cách làm việc của người đó.
    // Lưu ý: Dùng tham chiếu (const auto&) vì unique_ptr không thể bị copy.
    for (const auto& nv : congTy) {
        nv->lamViec(); 
    }

    // Dọn dẹp bộ nhớ: 
    // KHÔNG CẦN VÒNG LẶP DELETE NỮA! (Nhờ unique_ptr tự động giải phóng bộ nhớ khi kết thúc block)

    return 0;
}