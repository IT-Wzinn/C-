//                                          Nạp chồng hàm ( Function Overloading ) 
#include <bits/stdc++.h>
using namespace std;

class Geeks {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }
};

int main() {
    Geeks gfg;
    
    // add() called with int values
    gfg.add(10, 2);

    // add() called with double value
    gfg.add(5.3, 6.2);

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                 Nạp Chồng Toán Tử ( Operator Overloading )
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    
    // Adding c1 and c2 using + operator
    Complex c3 = c1 + c2;  
    cout << c3.real << " + i" << c3.imag;
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                          Ghi đè hàm ( Override )
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- LỚP CHA ---
class NhanVien {
protected:
    string ten;
public:
    NhanVien(string t) : ten(t) {}
    
    // Hàm ảo (Virtual) để lớp con có thể Overriding
    virtual void tinhLuong() const {
        cout << ten << " co luong mac dinh: 0 VND" << endl;
    }

    virtual ~NhanVien() {} // Luôn có virtual destructor
};

// --- LỚP CON 1 ---
class NhanVienVanPhong : public NhanVien {
public:
    NhanVienVanPhong(string t) : NhanVien(t) {}

    // Overriding: Viết lại hàm của cha
    void tinhLuong() const override {
        cout << ten << " (Van Phong) luong: 10.000.000 VND" << endl;
    }
};

// --- LỚP CON 2 ---
class NhanVienKinhDoanh : public NhanVien {
public:
    NhanVienKinhDoanh(string t) : NhanVien(t) {}

    // Overriding: Viết lại hàm của cha theo cách khác
    void tinhLuong() const override {
        cout << ten << " (Kinh Doanh) luong: 5.000.000 + Hoa hong" << endl;
    }
};

int main() {
    // TẠI SAO LẠI DÙNG CON TRỎ LỚP CHA? 
    // Vì ta có thể nhét tất cả các loại nhân viên vào cùng một "túi" (vector)
    vector<NhanVien*> danhSachNV;

    danhSachNV.push_back(new NhanVienVanPhong("Nguyen Van A"));
    danhSachNV.push_back(new NhanVienKinhDoanh("Tran Thi B"));
    danhSachNV.push_back(new NhanVienVanPhong("Le Van C"));

    cout << "--- BANG LUONG CONG TY ---" << endl;

    // Chỉ cần 1 vòng lặp duy nhất để điều khiển mọi loại nhân viên
    for (NhanVien* nv : danhSachNV) {
        // Dù 'nv' là con trỏ NhanVien, nhưng nó sẽ gọi đúng hàm Overriding của lớp con
        nv->tinhLuong(); 
    }

    // Dọn dẹp bộ nhớ
    for (NhanVien* nv : danhSachNV) delete nv;

    return 0;
}