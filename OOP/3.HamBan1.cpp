#include <iostream>
using namespace std;

class Nhanvien{
private:
    int salary;
    
public:
    Nhanvien();                                  // Hàm khởi tạo 
    friend void Tangluong(Nhanvien &a);         // Bản chất của hàm BẠN vẫn là hàm bên ngoài nên phải truyền tham số vào mỗi khi gọi hàm
};

Nhanvien::Nhanvien(){
    cout << "Nhập lương: ";
    cin >> salary;
    cout << "Lương của nhân viên là: " << salary << endl;
}

void Tangluong(Nhanvien &a){
    a.salary *= 2;
    cout << "Lương sau khi tăng là: " << a.salary << endl;
}

int main(){
    Nhanvien a;
    Tangluong(a);
}

/*                                           So sánh Hàm thành viên và Hàm bạn

Tạo Hàm Bạn tương tự như tạo hàm thường của C++ nên cần phải tự truyền tham số vào chứ tham số không gọi hàm được 
Hàm bạn không thuộc lớp nào, nhưng có thể “thâm nhập” nhiều lớp.
Hàm thành viên là người trong nhà, nhưng chỉ trong một nhà duy nhất.
Bản chất của hàm Bạn vẫn là hàm bên ngoài nên phải truyền tham số vào mỗi khi gọi hàm
*/