#include <iostream>
using namespace std;

class Person {
    
protected:              // Protected: Lớp con truy cập được
    string name;      
    int age;

public:
    void Input() {
        cout << "Nhập tên: ";
        getline(cin, name);
        cout << "Nhập tuổi: ";
        cin >> age;
        cin.ignore();    
    }

    void Output(){
        cout << "Tên: " << name << endl;
        cout << "Tuổi: " << age << endl;
    }
   
};

class Student : public Person {

};

int main() {
    Student s;
    s.Input();
    s.Output();
}


/*                  Truy Cập

Public: Ai cũng truy cập được.
Private: Hàm thành viên, Hàm bạn truy cập được.
Protected: Hàm thành viên, Hàm bạn, Lớp con truy cập được.


*/