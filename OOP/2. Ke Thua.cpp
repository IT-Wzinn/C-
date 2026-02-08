#include <iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;

public:
    Person() : name("Unknown"), age(0) {}                   // Constructer mặc định
    Person(string x, int y) : name(x), age(y) {}           // Constructer tự chỉnh

    void Output() const{
        cout << "Tên: " << name << endl;
        cout << "Tuổi: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person{
private:
    int id;

public:
    Student() : Person(), id(0) {}                         
    Student(string x, int y, int z) : Person(x,y), id(z) {}

    void Output() const{
        Person::Output();
        cout << "ID: " << id << endl << endl;
    }
};

int main(){
    Student a;
    a.Output();
    
    Student b("Quốc Vinh", 20, 43);
    b.Output();
}

/*                                        Truy Cập

_ Bản chất của kế thừa là tạo ra một biến con có sẵn một lớp cha nằm trong đó rồi tự thêm cái khác vào:  Student = Person + phần riêng của Student

Public: Ai cũng truy cập được.
Private: Hàm thành viên, Hàm bạn truy cập được.
Protected: Hàm thành viên, Hàm bạn, Lớp con truy cập được.


Cấu trúc của một lớp con 
Student a
└── Person part
    ├── name 
    └── age   

*/