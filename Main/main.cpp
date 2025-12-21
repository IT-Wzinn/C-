#include <iostream>
using namespace std;


class Animal{
public:
    virtual void Tiengkeu(){
        cout << "Tiếng kêu của động vật: " << endl;
    }; 
};

class Dog : public Animal{
public:
    void Tiengkeu() override{
        cout << "GÂU GÂU" << endl;
    };
};

class Cat : public Animal{
public: 
    void Tiengkeu() override{
        cout << "Meow Moew" << endl;
    };
};


void Keu(Animal* a){
    a->Tiengkeu();
}

int main(){
    Dog a;
    Cat b;

    Keu(&a);
    Keu(&b);
}