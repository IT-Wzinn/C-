#include <bits/stdc++.h>
using namespace std;

struct Sinhvien{
    string name;
    int age;
};

void Nhap(Sinhvien &x){                         // Lưu Ý mỗi khi nhập giá trị cho hàm số truyền vào thì phải sài THAM CHIẾU &   
        cout << "Nhập tên: ";                  
        getline(cin, x.name);

        cout << "Nhập tuổi: ";
        cin >> x.age;
    }

void In(const Sinhvien &x){                                 // const tránh thay đổi thuộc tính, & truy cập trực tiếp biến tránh tạo thêm bản sao 
        cout << "Tên của Sinh viên: " << x.name << endl;
        cout << "Tuổi của Sinh viên: " << x.age;
    }

int main(){
    Sinhvien a;        
    Nhap(a);
    In(a);
}       