#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    
    vector<int> a = {1, 2, 3, 4, 5};
    cout << "Số lượng phần tử: " << a.size() << endl;       // a.length();
    cout << "Kích thước: " << sizeof(a) << endl;          
    cout << "Phần tử đầu: " << a.front() << endl;
    cout << "Phần tử cuối: " << a.back() << endl;
    cout << "Kiểm tra vector có rỗng hay không: " << a.empty() << endl; // Xuất ra 0 nếu false 1 nếu true

    cout << "Sắp xếp vector a theo thứ tự từ nhỏ tới lớn: " << endl;
    sort(a.begin(), a.end());
    for (int i : a){
        cout << i << " ";
    }

    cout << "Đảo ngược vector: " << endl;
    reverse(a.begin(), a.end());
    for (int i : a){
        cout << i << " ";
    }
}

                              Lưu ý

substr  ( LẤY )
s.substr(n)        :  Lấy từ n đến hết chuỗi
s.substr(index, n) :  Lấy n phần tử từ index

erase   ( XÓA )
s.erase(n)         :  Xóa từ n đến hết
s.erase(index, n)  :  Xóa từ index n phần tử 

** LƯU Ý: 
Substr(): Chỉ có tác dụng đối với chuỗi ( string )
Erase():  Còn có thể sử dụng ở các Container khác ( vector, deque, list ).


vector
a.push_back(n);    Thêm phần tử vào cuối vector
a.pop_back(n);     Xóa phần tử ở cuối vector

Còn deque thì: 
deque<int> d;
d.push_back();      // Thêm vào cuối
d.pop_back();      // Xóa cuối
d.push_front();   // Thêm vào đầu
d.pop_front();   // Xóa đầu