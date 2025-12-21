#include <iostream>
using namespace std;

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

int main(){
    Student a;
    a.Input();
    a.Output();
}

/* 

_ Function hiding: Hàm con ghi đè hàm của class cha theo kiểu kế thừa.
_ Lưu ý khi gọi hàm của lớp cha ở lớp con thì phải tạo hàm trùng tên ở lớp con rồi muốn ghi đè thêm gì thì ghi.

*/
