#include <iostream>
#include <string>

using namespace std;

// ==========================================
// --- LỚP CHA (Base Class) ---
// Định nghĩa cái khung chung cho MỌI loại tài khoản
// ==========================================
class TaiKhoan {
protected: 
    // TÍNH KẾ THỪA: Dùng 'protected' để lớp con có thể "thấy" 
    // và dùng được các biến này, nhưng bên ngoài class thì không.
    string soTaiKhoan;
    string tenChuThe;
    double soDu;

public:
    // Constructor của lớp cha
    TaiKhoan(string stk, string ten, double tien) {
        soTaiKhoan = stk;
        tenChuThe = ten;
        soDu = (tien >= 0) ? tien : 0;
    }

    virtual ~TaiKhoan() {}

    // Các phương thức CHUNG mà tài khoản nào cũng phải có
    void napTien(double soTien) {
        if (soTien > 0) {
            soDu += soTien;
            cout << "[Tai Khoan] " << tenChuThe << " nap thanh cong " << soTien << " VND." << endl;
        }
    }

    void xemThongTin() const {
        cout << "STK: " << soTaiKhoan << " | Chu the: " << tenChuThe 
             << " | So du: " << soDu << " VND" << endl;
    }
};

// ==========================================
// --- LỚP CON 1: Tài Khoản Thường ---
// Kế thừa toàn bộ từ TaiKhoan
// ==========================================
class TaiKhoanThuong : public TaiKhoan {
public:
    // TÁI SỬ DỤNG KHỞI TẠO: Nhờ lớp cha khởi tạo giúp các thuộc tính chung
    TaiKhoanThuong(string stk, string ten, double tien) : TaiKhoan(stk, ten, tien) {}

    // Phương thức riêng: Rút tiền cơ bản (Không được rút quá số dư)
    bool rutTien(double soTien) {
        if (soTien > 0 && soTien <= soDu) {
            soDu -= soTien;
            cout << "=> [TK Thuong] Rut thanh cong " << soTien << " VND." << endl;
            return true;
        }
        cout << "=> [TK Thuong] Rut that bai! So du khong du." << endl;
        return false;
    }
};

// ==========================================
// --- LỚP CON 2: Tài Khoản Tín Dụng ---
// Kế thừa từ TaiKhoan nhưng MỞ RỘNG thêm tính năng
// ==========================================
class TaiKhoanTinDung : public TaiKhoan {
private:
    double hanMucTinDung; // Thuộc tính MỞ RỘNG riêng của lớp con

public:
    // Mượn cha khởi tạo phần chung, tự khởi tạo phần riêng (hanMuc)
    TaiKhoanTinDung(string stk, string ten, double tien, double hanMuc) : TaiKhoan(stk, ten, tien), hanMucTinDung(hanMuc) {}

    // Phương thức riêng: Rút tiền tín dụng (Được rút lố vào hạn mức)
    bool rutTien(double soTien) {
        if (soTien > 0 && soTien <= (soDu + hanMucTinDung)) {
            soDu -= soTien; // Số dư có thể bị âm
            cout << "=> [TK Tin Dung] Rut thanh cong " << soTien << " VND." << endl;
            return true;
        }
        cout << "=> [TK Tin Dung] Rut that bai! Vuot qua han muc tin dung." << endl;
        return false;
    }

    // Phương thức MỞ RỘNG: Chỉ thẻ tín dụng mới có
    void xemHanMuc() const {
        double hanMucConLai = (soDu < 0) ? (hanMucTinDung + soDu) : hanMucTinDung;
        cout << "   -> Han muc tin dung con lai: " << hanMucConLai << " VND." << endl;
    }
};

// ==========================================
// PHẦN VẬN HÀNH (Hàm Main)
// ==========================================
int main() {
    cout << "--- HE THONG NGAN HANG (TINH KE THUA) ---\n" << endl;

    // Khởi tạo 2 loại thẻ khác nhau
    TaiKhoanThuong tk1("111222", "Nguyen Van A", 50000);
    TaiKhoanTinDung tk2("999888", "Tran Thi B", 10000, 500000); // B có 10k dư, hạn mức 500k

    // 1. TÁI SỬ DỤNG PHƯƠNG THỨC: 
    // Lớp con không hề viết lại hàm napTien(), nhưng vẫn xài được ngon lành
    tk1.napTien(20000); // A lên 70k
    tk2.napTien(50000); // B lên 60k

    cout << "\n--- THUC HIEN RUT TIEN ---" << endl;
    tk1.rutTien(100000); // A thất bại (Chỉ có 70k, không được rút lố)
    tk2.rutTien(300000); // B thành công (Rút lố 240k vào hạn mức)

    cout << "\n--- THONG TIN SAU GIAO DICH ---" << endl;
    // Tái sử dụng hàm xemThongTin() của lớp cha
    tk1.xemThongTin(); 
    
    tk2.xemThongTin(); 
    tk2.xemHanMuc(); // Dùng hàm mở rộng của riêng lớp con

    return 0;
}