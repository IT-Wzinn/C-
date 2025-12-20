                                        Đóng gói: 

1) Khi nào dùng: 
_ Dùng khi muốn che giấu dữ liệu bên trong và kiểm soát cách truy cập.
_ Khi nào dùng: Không muốn bên ngoài sửa bừa dữ liệu
_ Muốn kiểm soát logic đọc / ghi

2) Vì sao phải dùng: 
_ Tránh dữ liệu bị gán sai
_ Dễ kiểm soát, dễ sửa logic sau này


                                        Kế thừa 
                                    
1) Khi nào dùng
_ Dùng khi nhiều class có điểm chung và muốn tái sử dụng code.
_ Có quan hệ is-a (Dog là Animal)
_ Tránh viết lại code giống nhau

2) Vì sao phải dùng
_ Giảm trùng lặp
_ Dễ mở rộng hệ thống
_ Đa hình: Gọi đúng hàm

                                        Đa Hình
                                        
1) Khi nào dùng
_ Dùng khi muốn gọi cùng 1 hàm nhưng hành vi khác nhau tùy object.
_ Có nhiều lớp con cùng hành vi nhưng cách làm khác
_ Muốn bỏ if/else

2) Vì sao phải dùng
_ Code gọn
_ Mở rộng không sửa code cũ


                                       Trừu Tượng
1) Khi nào dùng
_ Hàm thuần ảo dùng khi muốn ép các lớp con phải có một hành vi chung, 
nhưng lớp cha không (hoặc không nên) cài đặt hành vi đó.
_ Thiết kế hệ thống lớn
_ Muốn tách interface và implementation

2) Vì sao phải dùng
_ Dễ thay đổi cách cài đặt
_ Người dùng class không cần biết chi tiết


                                         OOP

Virtual → quyết định lúc chạy
Không virtual → quyết định lúc biên dịch


_ Khai báo bên trong: void Nhap();
_ Định nghĩa bên ngoài: void Sinhvien::Nhap(){}

_ Biến == Thuộc tính || Hàm == Phương thức



class Person{


    void Printf();
};

void Person::Printf(){              // Định nghĩa hàm bên ngoài
    
}

class Student : public Person{      // Kế thừa

};


                                    Quyền Truy Cập

| Phạm vi truy cập / Nơi truy cập | Bên trong chính class | Class con (kế thừa) | Code bên ngoài | Friend |
| ------------------------------- | --------------------- | ------------------- | -------------- | ------ |
| public                          | ✅                   | ✅                  | ✅             | ✅     |
| protected                       | ✅                   | ✅                  | ❌             | ✅     |
| private                         | ✅                   | ❌                  | ❌             | ✅     |




                                    Hàm Bạn
                                    
Khai báo Hàm Bạn bên trong Class: friend void Tangluong(Nhanvien &a);
Do bản chất vẫn là hàm bên ngoài nên chỉ có thể truyền tham số vào chứ không như hàm nội bộ: Tangluong(a);


                                    Kế Thừa
                                    
_ Phải là protected thì lớp con mới kế thừa được
_ Hàm con thừa hưởng mọi thứ từ hàm cha trừ thuộc tính private

Hàm kế thừa: class Student : public Person{};


                                  Đa Hình

_ Compile -> Runtime : virtual cho phép đa hình giúp chương trình chọn đúng đối tượng thực sự lúc runtime
_ Đa hình là việc gọi hàm lớp cha nhưng thực thi hành vi của lớp con, thông qua con trỏ hoặc tham chiếu
_ Đa hình là Runtime Polymorphism: Quyết định hàm được gọi khi chương trình chạy, không phải lúc biên dịch.


_ Điều kiện để có Đa Hình:
Hàm cha có virtual để runtime chọn chính xác được đối tượng thật sự chứ không sử dụng đối tượng của con trỏ
Gọi qua con trỏ/ tham chiếu của lớp cha nhưng thực hiện thành vi của lớp con
==> Đa Hình 

_ vitural: Giúp chương trình gọi đúng hàm của đối tượng thật, chứ không gọi theo kiểu con trỏ/ tham chiếu của lớp cha
_ override: Kiểm tra xem hàm ở lớp con thực sự có đang ghi đè một hàm virtual nào đó ở lớp cha hay không 

 

                                  Trừu Tượng

_ Tạo ra một hàm thuần ảo thay vì định nghĩa {} thành = 0, và bắt buột lớp con phải override thì chương trình mới được phép chạy 

_ Hàm thuần ảo: Hàm thuần ảo dùng khi muốn ép các lớp con phải có một hành vi chung nhưng khác cách thực hiện

class Animal{                            // Lớp trừu tượng
public: 
    virtual void Sound() = 0;           // Hàm thuần ảo (=0): Mục tiêu là động vật nào cũng phải biết kêu
};

==> Mọi lớp con muốn tạo object -→ bắt buộc override hàm thuần ảo


_ Lớp trừu tượng không thể tạo đối tượng được