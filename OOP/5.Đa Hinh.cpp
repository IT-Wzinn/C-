#include <iostream>
using namespace std;


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

/*  

Đa Hình là khi gọi một hành động thì thực hiện chính xác tính chất của đối tượng đó thông qua con trỏ lớp cha 

*/