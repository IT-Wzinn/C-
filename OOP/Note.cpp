                                        Đóng gói: 

_ Dùng khi muốn che giấu dữ liệu bên trong và kiểm soát cách truy cập.
_ Khi nào dùng: Không muốn bên ngoài sửa bừa dữ liệu
_ Muốn kiểm soát logic đọc / ghi


                                        Kế thừa 
                                    
_ Dùng khi nhiều class có điểm chung và muốn tái sử dụng code.
_ Tránh viết lại code giống nhau
_ Dễ mở rộng hệ thống

                                        Đa Hình

_ Đa hình: Gọi đúng hàm
_ Dùng khi muốn gọi cùng 1 hàm nhưng hành vi khác nhau tùy object.
_ Có nhiều lớp con cùng hành vi nhưng cách làm khác
_ Muốn bỏ if/else
_ Mở rộng không sửa code cũ


                                       Trừu Tượng
_ Hàm thuần ảo dùng khi muốn ép các lớp con phải có một hành vi chung, 
nhưng lớp cha không (hoặc không nên) cài đặt hành vi đó.
_ Thiết kế hệ thống lớn
_ Người dùng class không cần biết chi tiết

======================================================================================================================================================================================================================================================================================================

                                         OOP

Virtual → quyết định lúc chạy
Không virtual → quyết định lúc biên dịch


_ Khai báo bên trong: void Nhap();
_ Định nghĩa bên ngoài: void Sinhvien::Nhap(){}
_ Biến == Thuộc tính || Hàm == Phương thức


(***) 


                            Khi nào sài 1 dấu : và 2 dấu : 
class Person{


    void Printf();
};

void Person::Printf(){              // Định nghĩa hàm bên ngoài ==> 2 dấu ::
    
}

class Student : public Person{      // Kế thừa ==> 1 dấu chấm :

};


                                    Đóng Gói ( Quyền truy cập )

| Phạm vi truy cập / Nơi truy cập | Bên trong chính class | Class con (kế thừa) | Code bên ngoài | Friend |
| ------------------------------- | --------------------- | ------------------- | -------------- | ------ |
| public                          | ✅                   | ✅                  | ✅             | ✅     |
| protected                       | ✅                   | ✅                  | ❌             | ✅     |
| private                         | ✅                   | ❌                  | ❌             | ✅     |

VD: 

class Nhanvien{
private:
    double salary;

public:
    void Setsalary();
    void Getsalary();
};

void Nhanvien::Setlary(){
    cout << "Nhập lương của nhân viên: ";
    cin >> salary;                                      // Do là hàm nội bộ nên truy cập thẳng vào salary được
}

void Nhanvien::Getsalary(){
    cout << "Lương của nhân viên là: " << salary;
}

void Chinhsualuong(Nhanvien &a){
    cout << "Nhập lương của nhân viên: ";
    cin >> a.salary;                                   // Do là hàm bên ngoài nên phải dùng biến Nhanvien để gọi thuộc tính ( a.salary )
}


                                    Hàm Bạn
                                    
Khai báo Hàm Bạn bên trong Class: friend void Tangluong(Nhanvien &a);
Do bản chất vẫn là hàm bên ngoài nên chỉ có thể truyền tham số vào chứ không như hàm nội bộ: Tangluong(a);



VD: 

class Nhanvien{

private: 
    int salary;

public: 
    friend void Tangluong(Nhanvien &a);             // Do bản chất vẫn là hàm bên ngoài nên phải truyền tham số vào hàm
};

void Tangluong(Nhanvien &a){
    a.salary *= 2;                                          // Do là hàm bên ngoài nên phải truy cập salary bằng a.salary
    cout << "Lương của nhân viên sau khi tăng là: ";
}


                                    Kế Thừa
                                    
_ Phải là protected thì lớp con mới kế thừa được
_ Hàm con thừa hưởng mọi thứ từ hàm cha trừ thuộc tính private

Hàm kế thừa: class Student : public Person{};


VD:

class Person{

protected:
    string name;
    int age;

public: 
    void Input(){
        cout << "Nhập tên: ";
        getline(cin, name);

        cout << "Nhập tuổi: ";
        cin >> age;
    };

    void Output(){
        cout << "Tên: " << name << endl;
        cout << "Tuổi: " << age;
    };
};

class Student : public Person{

};



                                    Ghi đè hàm của lớp cha ở lớp con

_ Function hiding: Hàm con ghi đè hàm của class cha theo kiểu kế thừa.
_ Lưu ý khi gọi hàm của lớp cha ở lớp con thì phải tạo hàm trùng tên ở lớp con rồi muốn ghi đè thêm gì thì ghi.


VD: 
class Person{

protected:
    string name;
    int age;

public: 
    void Input(){
        cout << "Nhập tên: ";
        getline(cin, name);

        cout << "Nhập tuổi: ";
        cin >> age;

        cin.ignore();
    };

    void Output(){
        cout << "Tên: " << name << endl;
        cout << "Tuổi: " << age << endl;
    };
};


class Student : public Person{

public:
    string address;

    void Input(){
        Person::Input();
        cout << "Nhập địa chỉ: ";
        getline(cin, address);
    };

    void Output(){
        Person::Output();
        cout << "Địa chỉ: " << address;
    };
    
};

                                  Đa Hình

_ Compile -> Runtime : virtual cho phép đa hình giúp chương trình chọn đúng đối tượng thực sự lúc runtime chứ không chọn đối tượng của con trỏ
_ Đa hình là việc gọi hàm lớp cha nhưng thực thi hành vi của lớp con, thông qua con trỏ hoặc tham chiếu


_ Điều kiện để có Đa Hình:
Hàm cha có virtual để runtime chọn chính xác được đối tượng thật sự chứ không sử dụng đối tượng của con trỏ
Gọi qua con trỏ/ tham chiếu của lớp cha nhưng thực hiện thành vi của lớp con
==> Đa Hình 

_ vitural: Giúp chương trình gọi đúng hàm của đối tượng thật, chứ không gọi theo kiểu con trỏ/ tham chiếu của lớp cha
_ override: Kiểm tra xem hàm ở lớp con thực sự có đang ghi đè một hàm virtual trùng chữ ký ở lớp cha hay không 



VD:

class Animal{
public:
    virtual void Tiengkeu(){                                    // virtual: Cho phép Đa Hình
        cout << "Tiếng kêu của động vật: " << endl;
    }; 
};

class Dog : public Animal{
public:
    void Tiengkeu() override{                                 // override: Giúp kiểm tra hàm hiện tại có đang ghi đè hàm virtual cùng chữ ký trên lớp cha hay không  
        cout << "GÂU GÂU" << endl;
    };
};

class Cat : public Animal{
public: 
    void Tiengkeu() override{
        cout << "Meow Moew" << endl;
    };
};


void Keu(Animal* a){                        // Hàm thực thi tính chất của Đa Hình
    a->Tiengkeu();
}

int main(){
    Dog a;
    Cat b;

    Keu(&a);
    Keu(&b);
}


                                  Trừu Tượng

_ Tạo ra một hàm thuần ảo thay vì định nghĩa {} thành = 0, và bắt buột lớp con phải override thì chương trình mới được phép chạy 
==> Mọi lớp con muốn tạo object -→ bắt buộc phải override hàm thuần ảo

_ Không được tạo đối tượng từ lớp trừu tượng vì mọi hàm trong lớp đều phải hoàn chỉnh thì mới cho phép tạo đối tượng được còn lớp trừu tượng thì không làm thế được vì có hàm thuần ảo

_ Chọn Tratien là hàm thuần ảo vì mọi hình thức thanh toán bắt buộc phải có hành vi “Trả tiền” ( Trừu tượng ), nhưng cách trả thì khác nhau ( Đa hình )


VD: 

class Thanhtoan{                                // Lớp trừu tượng
public: 
    virtual void Tratien(int sotien) = 0;      // Hàm thuần ảo (=0): Bắt buột lớp con phải có hàm Tratien nếu không thì không chạy được
};

class Tienmat : public Thanhtoan{
public:     
    void Tratien(int sotien) override{                                      // override để kiểm tra
        cout << "Đang trả tiền bằng tiền mặt: " << sotien << endl;
    }
};

class Thenganhang : public Thanhtoan{
public:     
    void Tratien(int sotien) override{
        cout << "Đang trả tiền bằng thẻ ngân hàng: " << sotien << endl;
    }
};

void Xulitratien(Thanhtoan* a){
    a->Tratien(100);
}

int main(){

    Thanhtoan* a = new Tienmat();
    Xulitratien(a);

    Thanhtoan* b = new Thenganhang();
    Xulitratien(b);
}