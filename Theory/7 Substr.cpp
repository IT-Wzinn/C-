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
s.substr(n)        :  Lấy từ vị trí n đến hết chuỗi
s.substr(index, n) :  Lấy n phần tử từ vị trí index

erase   ( XÓA )
s.erase(n)         :  Xóa từ vị trí n đến hết
s.erase(index, n)  :  Xóa từ vị trí index n phần tử 
  
a.insert(pos, "xyz"): Thêm xyz vào mảng a.
a.replace(pos, len, "xyz") : Thay thế chuỗi từ vị trí pos độ dài len của chỗi a bằng chuỗi "xyz".

** LƯU Ý: 
Substr(): Chỉ có tác dụng đối với chuỗi
Erase():  Còn có thể sử dụng ở các Container ( vector, deque, list ).