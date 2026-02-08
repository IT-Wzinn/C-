#include <iostream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    
    int i = 0;
    while(i < s.size() && s[i] == ' '){
        i++;
    }

    //Xóa i khoảng trắng đầu chuỗi: 
    s = s.substr(i);
    cout << s << endl; 
    
    // Xóa i khoảng trắng cuối chuỗi  
    string b;
    getline(cin, b);
    int j = b.size() - 1;
    
    while(j >= 0 && b[j] == ' '){
        j--;
    }
    
    // s.substr(pos, n); n là số lượng nên j phải cộng thêm 1
    b = b.substr(0, j + 1);
    cout << b;
}

/*
substr
s.substr(pos)    : Lấy phần tử sau pos
s.substr(pos, n) : Lấy n phần tử sau pos

erase
s.erase(pos)     : Lấy phần tử trước pos
s.erase(pos, n)  : Lấy n phần tử trước pos
*/