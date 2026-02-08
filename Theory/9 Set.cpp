#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> a;
    a.insert(3);
    a.insert(5);
    a.insert(7);
    
    cout << "Duyệt set bằng Range based for loop : \n";
    for(int i : a){
        cout << i << " ";
    }
    cout << "\nDuyệt Set bằng iterator : \n";
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *it << " ";
    }
    cout << "\nDuyệt ngược Set bằng iterator : \n";
    for(set<int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++){
        cout << *it << " ";
    }
}

                                   Lưu ý
Các phần tử trong set có giá trị khác nhau, không có 2 phần tử có cùng giá trị
Các phần tử trong set được tự động sắp xếp theo thứ tự tăng dần     // Map cũng thế
Set không thể truy cập phần tử thông qua chỉ số như mảng hay vector, string.
Set đặc biệt phù hợp với những bài toán liên quan tới việc loại bỏ giá trị trùng nhau hoặc tìm kiếm nhanh.


==========================================================================================================================================================================================================================================
Hàm	                 Chức năng
size();   	  Số lượng phần tử trong set
insert();	  Thêm phần tử vào trong set
empty();      Kiểm tra set rỗng, nếu đúng trả về true (1), ngược lại trả về false(0)
clear();   	  Xóa toàn bộ phần tử trong set

==========================================================================================================================================================================================================================================
***LƯU Ý:
Map và set sẽ tự động sắp xếp theo thứ tự tùy theo loại kiểu dữ liệu ví dụ char thì sẽ sắp xếp theo alpha Bet, int thì theo giá trị từ bé tới lớn    
nên nếu muốn xuất ra đúng theo đúng thứ tự truyền vào thì cần phải truyền vào vector trước rồi mới truyền vào set ( Nếu ptử chưa có trong set/map thì thêm vào vector vào vector trước rồi mới thêm vào set/map)

    int x;
    set<int> s;
    vector<int> v;

    for (int i = 0; i < n; i++) {
    cin >> x;
    if (s.find(x) != s.end()){  
        v.push_back(x);         
    }
        s.insert(x);          
    }