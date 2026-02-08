#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    vector<int> v = {1,2,3,4,5};
    
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";                                      // Duyệt Array bằng iterator 
    }

    for(auto it = a.begin(); it != a.end(); it++){              // Duyệt Set bằng iterator
        cout << *it << " ";                             
    }

    for(auto it = a.begin(); it != a.end(); it++){              // Duyệt Map bằng iterator (*)
        cout << "Key: " << it->first << " value: " << it->second << endl;  
    }
}   
                                Trick Con Trỏ Iterrator Khi Làm Việc Với Các Container

vector<int> a = {1,2,3,4,5,2,2,3,4,4,4};

1) Phần tử lớn nhất trong Container.
auto it = max_element(a.begin(), a.end());                

2) Phần tử nhỏ nhất trong Container.
auto it = min_element(a.begin(), a.end());                

3) Trỏ it đến phần tử mình muốn tìm 
auto it = find(a.begin(), a.end(), 2);         


                                Vị trí và số lượng phần tử trong Container

1) Vị trí của phần tử mình muốn tìm.
int index = distance(a.begin(), it);                        

2) Đếm số lượng của phần tử mình muốn biết trong Container xem nó có số lượng bao nhiêu.
int a = count(v.begin(), v.end(), 2);                    