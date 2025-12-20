#include <iostream>
using namespace std;

class Animal{
public:
    virtual void Sound(){             // virtual giúp runtime quyết định chính xác đối tượng thật, chứ không gọi theo đối tượng của con trỏ/ tham chiếu từ lớp cha
        cout << "Animal sound";
    }
};

class Dog : public Animal{
public:
    void Sound() override{                   // override giúp kiểm tra xem hàm này có đang ghi đè với hàm virtual nào ở lớp cha hay không
        cout << "Dog Sound";
    }
};

class Cat : public Animal{
public:
    void Sound() override{
        cout << "Cat Sound";
    }
};

void Keu(Animal* a){            
    a->Sound();
}

int main(){
    Animal* a = new Dog;               // Cách gọi chuẩn đa hình
    a->Sound(); 

    Cat b;                             // Cách gọi bằng hàm, hàm Keu() thể hiện đúng lợi ích của Đa Hình đó là gọi đúng hàm của đối tượng
    Keu(&b);

    Animal c;                          // Gọi trực tiếp không thông sử dụng đa hình 
    c.Sound();           
}



/*

_ Do Dog kế thừa Animal nên con trỏ Dog* có thể ép kiểu lên Animal* và truyền vào hàm Tiengkeu.

_ Khi gọi a->Sound(), vì Sound là hàm virtual, nên tại runtime C++ sẽ dựa vào kiểu 
đối tượng thực sự mà con trỏ đang trỏ tới (Dog) để gọi đúng hàm Dog::Sound(), thay vì Animal::Sound().


*/