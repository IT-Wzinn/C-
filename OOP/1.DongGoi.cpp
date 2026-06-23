#include <iostream>
#include <string>

using namespace std;

class ViTien {
private:
    // TÍNH ĐÓNG GÓI: Dữ liệu nhạy cảm được giấu kín, bên ngoài không thể chạm vào.
    string chuNhan;
    double soTien;

public:
    // Constructor khởi tạo ví
    ViTien(string ten, double tienBanDau) {
        chuNhan = ten;
        soTien = (tienBanDau >= 0) ? tienBanDau : 0;
    }

    // TÍNH ĐÓNG GÓI: Cửa ngõ (phương thức public) để thao tác với dữ liệu private một cách an toàn.
    void themTien(double tien) {
        if (tien > 0) {
            soTien += tien;
            cout << "[Tuong tac] " << chuNhan << " vua them " << tien << " VND vao vi." << endl;
        }
    }

    void xemVi() const {
        cout << "Vi cua " << chuNhan << " hien co: " << soTien << " VND." << endl;
    }

    // KHAI BÁO HÀM BẠN: Cho phép một hàm ngoại lai được quyền "phá vỡ" tính đóng gói của class này.
    friend void gopTien(ViTien& vi1, ViTien& vi2);
};

// =================================================================
// ĐỊNH NGHĨA HÀM BẠN (Đứng hoàn toàn bên ngoài class như một hàm tự do)
// =================================================================
void gopTien(ViTien& vi1, ViTien& vi2) {
    // Nhờ là "bạn", hàm này có thể chọc thẳng vào biến 'soTien' (vốn là private)
    double tongTien = vi1.soTien + vi2.soTien; 
    
    cout << "\n=> [Ham Ban] Tong tai san cua " << vi1.chuNhan 
         << " va " << vi2.chuNhan << " la: " << tongTien << " VND.\n" << endl;
}

int main() {
    cout << "--- TRUOC KHI GIAO DICH ---" << endl;
    ViTien viAn("An", 50000);
    ViTien viBinh("Binh", 120000);

    viAn.xemVi();
    viBinh.xemVi();

    cout << "\n--- THUC HIEN DONG GOI ---" << endl;
    // An không thể tự viết: viAn.soTien = 1000000; (Sẽ báo lỗi biên dịch)
    // Bắt buộc phải thông qua phương thức hợp lệ
    viAn.themTien(20000); 

    // Gọi Hàm Bạn
    gopTien(viAn, viBinh);

    return 0;
}