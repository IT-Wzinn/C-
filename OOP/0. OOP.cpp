#include <bits/stdc++.h>
using namespace std;

class Sinhvien{

// 1. Private data
private:
    string name;

public:

// 2. Constructor
    Sinhvien() : name("Unknown") {}
    Sinhvien(const string &n) : name(n) {}

// 3. Getter / Setter
    void Setname(const string &n){
    name = n;
    }
    
    const string &Getname() const{
        return name;
    }

// 4. Logic method
    void ChuanhoaTen(){

        stringstream ss(name);
        string word;
        string result = "";

        while(ss >> word){

            word[0] = toupper(word[0]);

            for(int i = 1; i < word.size(); i++)
                word[i] = tolower(word[i]);

            result += word + " ";
        }

        if(!result.empty())
            result.pop_back();

        name = result;
    }

// 5. UI
    void Nhap(){
        string temp;

        cout << "Hãy nhập tên: ";
        getline(cin >> ws, temp);

        Setname(temp);
    }

    void Xuat() const{
        cout << endl << "Kết quả: ";
        cout << Getname() << endl;
    }

};

int main(){
    Sinhvien a;
    a.Nhap();
    a.ChuanhoaTen();   // logic xử lý dữ liệu
    a.Xuat();
}


/*
void Setname(const string &n): Truy cập trực tiếp và không cho thay đổi tham số truyền vào 
const string &Getname() const{}: Const đầu không cho sửa dữ liệu trả về, Const sau không cho thay đổi thuộc tính của oject

Thứ tự của một Class:
1. private data
2. constructor / destructor
3. getter / setter
4. các method xử lý logic
5. các hàm UI ( Hiển thị nhập xuất)

*/