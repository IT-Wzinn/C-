// So sánh sự khác nhau giữa cách gọi giữa sài hàm Thường và Hàm Bạn
#include <iostream>
using namespace std;

class Nhanvien{
private:
    int salary;
    
public:
    Nhanvien();                                   
    void Tangluong();         
};

Nhanvien::Nhanvien(){
    cout << "Nhập lương: ";
    cin >> salary;
    cout << "Lương của nhân viên là: " << salary << endl;
}

void Nhanvien::Tangluong(){
    salary *= 2;
    cout << "Lương sau khi tăng là: " << salary;
}

int main(){
    Nhanvien a;
    a.Tangluong();
}

/*
_ Hàm nội bộ thì chỉ cần . để gọi hàm 
_ Còn hàm bạn thì phải tự truyền tham số của đối tượng  
*/