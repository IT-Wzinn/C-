#include <iostream>
using namespace std;

class Animal{
public:
    virtual void Tiengkeu(){                                    // virtual: Cho phép Đa Hình
        cout << "Tiếng kêu của động vật: " << endl;
    }

    virtual ~Animal(){};            // Destructer do người dùng tự tạo nhằm phân biệt với Class không giữ tài nguyên thì sẽ sài Destructer mặc định 
};

class Dog : public Animal{
    public:
    void Tiengkeu() override{                                 // override: Giúp kiểm tra hàm hiện tại có đang ghi đè hàm virtual cùng chữ ký trên lớp cha hay không  
        cout << "GÂU GÂU" << endl;
    }

     ~Dog(){}
};

class Cat : public Animal{
    public: 
    void Tiengkeu() override{
        cout << "Meow Moew" << endl;
    };

     ~Cat(){}
};

void Keubangcontro(Animal* a){                       
    a->Tiengkeu();                          
}

void Keubangthamchieu(Animal& a){
    a.Tiengkeu();
};


int main(){

    // Tạo trực tiếp đối tượng
    Dog a;
    Cat b;

    Keubangcontro(&a);
    Keubangthamchieu(b);

    
    // Tạo đối tượng bằng Cấp Phát Động  ==> Phải có virtual ở Destructer của Animal để C++ biết mà không xóa xót đối tượng nếu không thì Destructer chỉ xóa mỗi đối tượng ~Animal(){}
    Animal* c = new Dog();
    Keubangcontro(c);
    Keubangthamchieu(*c);
    
    delete c;           // Nếu đối tượng được tạo bằng Cấp phát động ( Vùng nhớ Head ) thì  C++ runtime không tự gọi Destructer sau khi ra khỏi Scope nên phải tự chủ động Delete 

}

/*  
_ Đa Hình là khi gọi một hành động thì thực hiện chính xác tính chất của đối tượng đó thông qua con trỏ lớp cha 

_ C++ quyết định hàm gọi tại lúc chạy, không phải lúc biên dịch ở đây là hàm Keu1 và Keu2 

_ Class nào có ít nhất 1 hàm virtual và dùng qua con trỏ base → Destructor PHẢI virtual

_ Tạo đối tượng trực tiếp ( Dog a; )                          ==> Stack → tự gọi Destructor khi ra khỏi Scsope 
_ Tạo đối tượng bằng cấp phát động ( Animal* a = new Dog(); ) ==> Heap → KHÔNG tự gọi, programmer phải chủ động delete            

_ virtual ~Animal(){} Destructer do người dùng tự viết dùng khi hiện tại chưa dọn gì hoặc sau này sẽ thêm cleanup, class có thể mở rộng hoặc muốn kiểm soát rõ destructor
_ virtual ~Thanhtoan() = default; Destructer mặc định của Compiler không cần cleanup thủ công, thường dùng cho abstract class, interface-style. base class chỉ định nghĩa hành vi
*/