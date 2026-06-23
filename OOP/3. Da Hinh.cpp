#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// --- LỚP CHA (Base Class) ---
// ==========================================
class TaiKhoan {
protected:
    string soTaiKhoan;
    string tenChuThe;
    double soDu;

public:
    TaiKhoan(string stk, string ten, double tien) {
        soTaiKhoan = stk;
        tenChuThe = ten;
        soDu = (tien >= 0) ? tien : 0;
    }

    // TÍNH ĐA HÌNH: Hàm ảo (Virtual) cho phép lớp con ghi đè
    // Quy tắc: Nếu có hàm virtual, Destructor cũng phải là virtual
    virtual ~TaiKhoan() {}

    // Hàm được thiết kế để bị ghi đè (Override)
    virtual void rutTien(double soTien) {
        if (soTien > 0 && soTien <= soDu) {
            soDu -= soTien;
            cout << "[Tai Khoan] Rut thanh cong " << soTien << " VND." << endl;
        } else {
            cout << "[Tai Khoan] Rut that bai! So du khong du." << endl;
        }
    }

    virtual void xemThongTin() const {
        cout << "STK: " << soTaiKhoan << " | Chu the: " << tenChuThe 
             << " | So du: " << soDu << " VND" << endl;
    }
};

// ==========================================
// --- LỚP CON 1: Tài Khoản Thường ---
// ==========================================
class TaiKhoanThuong : public TaiKhoan {
public:
    TaiKhoanThuong(string stk, string ten, double tien) : TaiKhoan(stk, ten, tien) {}

    // Ghi đè hàm của lớp cha
    void rutTien(double soTien) override {
        cout << "-> (Dang xu ly Tai Khoan Thuong) " << endl;
        if (soTien > 0 && soTien <= soDu) {
            soDu -= soTien;
            cout << "=> Rut thanh cong " << soTien << " VND. (Con lai: " << soDu << " VND)" << endl;
        } else {
            cout << "=> [Loi] So du " << soDu << " VND khong du de rut " << soTien << " VND." << endl;
        }
    }
};

// ==========================================
// --- LỚP CON 2: Tài Khoản Tín Dụng ---
// ==========================================
class TaiKhoanTinDung : public TaiKhoan {
private:
    double hanMucTinDung;

public:
    TaiKhoanTinDung(string stk, string ten, double tien, double hanMuc) : TaiKhoan(stk, ten, tien), hanMucTinDung(hanMuc) {}

    // Ghi đè hàm của lớp cha, cách hoạt động hoàn toàn khác
    void rutTien(double soTien) override {
        cout << "-> (Dang xu ly Tai Khoan Tin Dung) " << endl;
        if (soTien > 0 && soTien <= (soDu + hanMucTinDung)) {
            soDu -= soTien;
            cout << "=> Rut thanh cong " << soTien << " VND. (Con lai: " << soDu << " VND)" << endl;
        } else {
            cout << "=> [Loi] Vuot qua han muc tin dung cho phep!" << endl;
        }
    }
    
    void xemThongTin() const override {
        TaiKhoan::xemThongTin();
        double hanMucConLai = (soDu < 0) ? (hanMucTinDung + soDu) : hanMucTinDung;
        cout << "   -> Han muc tin dung con lai: " << hanMucConLai << " VND" << endl;
    }
};

// ==========================================
// PHẦN VẬN HÀNH (Hàm Main)
// ==========================================
int main() {
    cout << "--- HE THONG ATM (TINH DA HINH) ---\n" << endl;

    // TÍNH ĐA HÌNH Ở MAIN: Dùng con trỏ lớp cha quản lý các lớp con
    vector<TaiKhoan*> danhSachThe;
    danhSachThe.push_back(new TaiKhoanThuong("111222", "Nguyen Van A", 50000));
    danhSachThe.push_back(new TaiKhoanTinDung("999888", "Tran Thi B", 10000, 500000));

    // Thực hiện thao tác giống hệt nhau trên các thẻ khác nhau
    for (TaiKhoan* the : danhSachThe) {
        the->xemThongTin();
        the->rutTien(100000); // Lệnh rút tiền giống nhau
        cout << "-----------------------" << endl;
    }

    // Dọn dẹp bộ nhớ (Nhờ virtual destructor)
    for (TaiKhoan* the : danhSachThe) {
        delete the;
    }

    return 0;
}
/*
virtual: Là "giấy phép" từ lớp cha, cho phép các lớp con được quyền định nghĩa lại (ghi đè) hàm đó.
override: Là "trình kiểm soát" ở lớp con, dùng để báo với trình biên dịch: "Tôi đang ghi đè đấy, hãy kiểm tra giúp tôi xem có đúng tên và tham số với lớp cha không".

Function Overloading: Cùng 1 tên hàm nhưng khác tham số (trong cùng 1 class).
Operator Overloading: Giúp các ký hiệu như +, -, * có thể làm việc được với Object (đối tượng).
Function Overriding: Lớp con viết lại hàm của lớp cha. Việc gọi lớp con thông qua con trỏ lớp cha là để đạt được tính Đa hình (Polymorphism) — giúp code của bạn có thể điều khiển hàng nghìn loại đối tượng khác nhau chỉ bằng một dòng lệnh duy nhất mà không cần biết chính xác loại nào ( ví dụ khi đang duyệt vòng lặp).


*/
