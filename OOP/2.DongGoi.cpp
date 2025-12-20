#include <iostream>
using namespace std;

class Nhanvien{
private:
    int salary;         

public:
    void Setsalary();
    void Getsalary();
};

void Nhanvien::Setsalary(){
    cin >> salary;
}

void Nhanvien::Getsalary(){
    cout << "Lương của nhân viên là: " << salary;
}

int main(){
    Nhanvien a;     
    a.Setsalary();            
    a.Getsalary();           
}


/* 
                                                         Đóng Gói
_ Là việc ẩn dữ liệu bên trong class (private) và chỉ cho phép truy cập thông qua các hàm (public) cùng Class, hoặc hàm Friend với Class đó
==> Mục đích: Bảo vệ dữ liệu, tránh bị chỉnh sửa sai cách.

Thêm điều kiện cho hàm Salary:

    void Setsalary(){
        int x;
        cout << "Nhập lương cho nhân viên: ";
        cin >> x;
        if(x <= 0) cout << "Nhập lương bị lỗi";
        else salary = x;
    }

*/