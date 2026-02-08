#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(){
    map<int, int> a;
    a.insert({1,2});  // Cách tạo key và value cơ bản
    a[3] = 4;        // Nếu key đó chưa có thì tự thêm Key đó vào map với value = 0
    
    // VD: a[1];   Có value = 0
    // VD: a[1]++; Có value = 1 
}
===================================================================================================================================================
cout << "Kích thước map: " << a.size() << endl;

cout << "Duyệt bằng Range based for loop: ";
for( auto i : a ){
    cout << "\nKey: " << i.first << " value: " << i.second;            // Nếu duyệt map bằng RBFL thì i.first 
}                                                                     // Nếu duyệt bằng Iterator thì i->first

cout << "Duyệt bằng Iterator: \n";
for(auto it = a.begin(); it != a.end(); it++){
    cout << "Key: " << it->first << " value: " << it->second << endl;  
}

cout << endl << endl;

cout << "Duyệt ngược bằng iterator: \n";
for(map<int,int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++){
        cout << "Key: " << it->first << " value: " << it->second << endl; 
}

===================================================================================================================================================
                              Tìm KEY có VALUE lớn nhất bằng BẢN CHẤT
// Cách 1: Bản chất
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main(){
    vector<char> v = {'a', 'b', 'a', 'c', 'b', 'a'}; 
    map<char, int> m;
    
    for(char c : v){
        m[c]++;
    }
    
    char kitudau = v[0];
    int valuemax = m[kitudau];
    
    for(int i = 0; i < v.size(); i++){
        if(valuemax < m[v[i]]){
           valuemax = m[v[i]];
           kitudau  = v[i];
        }
    }

cout << "Kí tự xuất hiện nhiều nhất là: " << kitudau << " với số lần: " << valuemax;

}

// Cách 2: Iterator
char kitu;
int max = INT_MIN;

for(auto it : a){
    if(it.second > max){
       max = it.second;
       kitu = it.first;
    }
}
===================================================================================================================================================
 
map<int,string> m;
    m[5] = "five";
    m[2] = "two";
    m[8] = "eight";
    m[1] = "one";
    m[4] = "four";

    cout << "Các phần tử trong map (tự động sắp xếp theo key): " << endl;
    for(auto i : m){
        cout << i.first << ": " << i.second << endl;        // map tự sắp xếp thứ tự theo thứ thứ tự của key
    }

Terminal:
Các phần tử trong map (tự động sắp xếp theo key): 
1: one
2: two
4: four
5: five
8: eight
===================================================================================================================================================
                                  Lưu Ý
a.[key] Nếu chưa có giá trị key đó thì không báo lỗi mà tự tạo value của key đó = 0 
a.at(key) Thường dùng để xem giá trị của value nếu chưa có key thì báo lỗi chứ không tạo thêm như a[key];       // An toàn hơn để đỡ phải tạo key nếu không cần thiết


***LƯU Ý:
Map và set sẽ tự động sắp xếp theo thứ tự tùy theo loại kiểu dữ liệu ví dụ char thì sẽ sắp xếp theo alpha Bet, int thì theo thứ tự từ bé tới lớn    
nên nếu muốn xuất đúng theo tuần thứ tự truyền vào thì cần phải truyền qua vector trước rồi mới xuất ra 

==> Làm điều kiện nếu chưa có trong set thì thêm vô Vector 