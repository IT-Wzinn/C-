#include <iostream>
using namespace std;
int main(){

    //Xóa khoảng trắng đầu câu
    string s;
    getline(cin, s);
    cout << "Kích thước của s lúc đầu: " << s.size() << endl;

    int i = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }

    s = s.substr(i+1);
    cout << "Kích thước của s lúc sau: " << s.size();
    

    // Xóa khoảng trắng ở cuối câu 
    string s;
    getline(cin, s);
    cout << "Kích thước của s lúc đầu: " << s.size() << endl;
    int i = 0;
    while(i < s.size() && s[i] != ' '){
        i++;
    }
    
    s.erase(i+1);
    cout << "Kích thước của s lúc sau: " << s.size();
}

// Chú thích
substr  ( LẤY )
s.substr(index)    :  Lấy từ index đến hết chuỗi
s.substr(index, n) :  Lấy n phần tử từ vị trí index

erase   ( XÓA )
s.erase(index)     :  Xóa từ vị trí index đến hết
s.erase(index, n)  :  Xóa từ vị trí index n phần tử 
  
insert
s.insert(index, "xyz")        : Thêm xyz vào sau vị trí index.

replace
s.replace(index, len, "xyz")  : Thay thế chuỗi từ vị trí index độ dài len của chỗi s bằng chuỗi "xyz".

** LƯU Ý: 
Substr(): Chỉ có tác dụng đối với chuỗi
Erase():  Còn có thể sử dụng ở các Container ( vector, deque, list ).