#include <iostream>
using namespace std;

class Sinhvien{
private:
    string name;
    int age;

public:
    void Nhap(){
        cout << "Nhập tên: ";
        getline(cin, name);
        
        cout << "Nhập tuổi: ";
        cin >> age;
    };
    
    void In() const{
        cout << "Tên của sinh viên là: " << name << endl;
        cout << "Tuổi của sinh viên là: " << age << endl << endl;
    };


    Sinhvien(){};                                                // Constructor mặc định 
    Sinhvien(string x, int y) : name(x), age(y) {};             //  Initializer list 
};

int main(){
    Sinhvien a;
    a.Nhap();
    a.In();

    Sinhvien b("Quốc Vinh", 20);
    b.In();
}

/*                                                 OOP

_ Class chỉ để giữ giữ liệu và logic còn cin, cout thì làm ở hàm main để cho Logic và UI tách riêng để sau này dễ mở rộng
_ Nếu đối tượng là const thì chỉ gọi được hàm cũng là const 
_ Hàm khởi tạo nên tạo theo kiểu Initializer list: Sinhvien(string x, int y) : name(x), age(y) {}
_ Initializer list được dùng để khởi tạo giá trị ban đầu của thuộc tính ngay sau khi tạo đối tượng, nếu có thuộc tính const/ & 
  thì bắt buột phải dùng Initializer list vì 2 cái đó không được NULL

_ Destructer: Tự động chạy khi object kết thúc vòng đời

~Sinhvien() {
   
}

*/