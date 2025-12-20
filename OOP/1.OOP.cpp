#include <iostream>
using namespace std;

class Sinhvien{
public:
    string name;
    int age;

    // Hàm nhập vào
    // Do đây là hàm nội bộ được chính ĐỐI TƯỢNG gọi nên không cần ghi a.name, a.age mà sài thẳng name, age
    // Khai báo hàm bên trong, định nghĩa hàm bên ngoài
    void Nhap();
    void In();
    
    Sinhvien();                   // Hàm khởi tạo ( Không có tham số )
    Sinhvien(string x, int y);   // Hàm khởi tạo ( Có tham số )

};

void Sinhvien::Nhap(){
        cout << "Nhập tên: ";
        getline(cin, name);

        cout << "Nhập tuổi: ";
        cin >> age;
}

void Sinhvien::In(){
    cout << "Tên của sinh viên là: " << name << endl;
    cout << "Tuổi của sinh viên là: " << age << endl;
}

Sinhvien::Sinhvien(){
        name = "Unknown";
        age = 0;
}

Sinhvien::Sinhvien(string x, int y){   
        name = x;
        age = y;
}

int main(){
    Sinhvien a;
    a.Nhap();      
    a.In();
    
    Sinhvien b;
    b.In();
    
    Sinhvien c("LQV", 19);
    c.In();
}

/* 
                                  Chú thích

| Loại     | Trong struct                       | Trong class                         |
| -------- | ---------------------------------- | ----------------------------------- |
|  Biến    | Biến thành viên                    | Thuộc tính                          |
|  Hàm     | Hàm thành viên                     | Phương thức                         |

Lưu ý:
_ Hàm được khai báo và định nghĩa trong Class phải khai báo đầy đủ: void Nhap(){...};
_ Còn hàm được định nghĩa bên ngoài void Sinhvien::In(){} thì vẫn cần phải khai báo bên trong Class 
_ Lưu ý là không có dấu {} vì có ngoặc nhọn là coi như đã định nghĩa rồi.


                                Hàm khởi tạo  
1) Không có tham số: 
Sinhvien(){                       
    name = "Unknown";
    age = 0;
}                                     

2) Có tham số: 
Sinhvien(string x, int y){       
    name = x;
    age = y;
}
                                        
| Chức năng                                       | Giải thích ngắn                                                   |
| ----------------------------------------------- | ----------------------------------------------------------------- |
| 1. Khởi tạo giá trị ban đầu                     | Gán giá trị mặc định cho thuộc tính khi tạo đối tượng.            |
| 2. Gọi tự động khi đối tượng được tạo           | Không cần gọi thủ công, hệ thống tự kích hoạt.                    |
| 3. Có thể có nhiều constructor (nạp chồng)      | Giúp tạo đối tượng theo nhiều cách khác nhau.                     |
| 4. Dùng để cấp phát tài nguyên                  | Dành cho trường hợp cần khởi tạo con trỏ, mở file, cấp bộ nhớ,... |
| 5. Luôn chạy trước mọi hàm khác trong class     | Giúp đảm bảo đối tượng có dữ liệu hợp lệ trước khi dùng.          |

*/