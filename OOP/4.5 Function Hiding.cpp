#include <iostream>
using namespace std;

class Person{
public:
     void Input(){
        cout << "Hi Person" << endl;
    }
};

class Student : public Person{
public:
    void Input() {
        cout << "Hi Student";
    }
};

int main(){
    Student a;
    a.Input();
}

// function hiding: Hàm con ghi đè hàm của class cha theo kiểu kế thừa.