#include <iostream>
#include <vector>
using namespace std;

struct SinhVien{
    string hoTen;
    int tuoi;
    double diemTB;
};

void Nhapsinhvien(SinhVien &sv){
    cout << "Nhap ho ten: ";
    getline(cin, sv.hoTen);        
    cout << "Nhap tuoi: ";
    cin >> sv.tuoi;
    cout << "Nhap diem trung binh: ";
    cin >> sv.diemTB;
    cin.ignore();  
}

void Inthongtin(const SinhVien &sv) {
    cout << "Ho ten: " << sv.hoTen 
         << ", Tuoi: " << sv.tuoi 
         << ", Diem TB: " << sv.diemTB << endl;
}

void Indanhsach(const vector<SinhVien> &ds){
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < ds.size(); i++){
        cout << "Sinh vien " << i + 1 << ": ";
        Inthongtin(ds[i]);
    }
}

int main(){
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;
    cin.ignore();   

    vector<SinhVien> danhSach;

    for (int i = 0; i < soLuong; i++){
        SinhVien sv;
        cout << "\nNhap thong tin cho sinh vien thu " << i + 1 << ":\n";
        Nhapsinhvien(sv);           
        danhSach.push_back(sv);    
    }

    Indanhsach(danhSach);         
}
