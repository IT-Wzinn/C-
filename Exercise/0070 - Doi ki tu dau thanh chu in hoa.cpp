#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    s[0] = toupper(s[0]);
    
    bool check = false;
    
    for(int i = 0; i < s.size(); i++){
        if(check){                 // Thực thi cờ
            s[i] = toupper(s[i]);
            check = false;              // Hủy cờ đánh dấu
        }
        // Đánh dấu cờ
        if(s[i] == ' ') check = true;
    }
    cout << s;
}
/* Dạng bài ĐÁNH DẤU ( Sài 2 điều kiện )
1 điều kiện để đánh dấu
1 điều kiện để thực hiện khi đã thỏa điều kiện và nhớ hủy đánh dấu sau khi thực hiện xong nếu cần
*/