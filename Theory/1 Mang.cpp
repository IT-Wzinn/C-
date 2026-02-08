#include <iostream>
using namespace std;
int main(){

    int mang1chieu[] = {1,2,3,4};           
    int mang2chieu[2][2] = {            // [2][2] ==> 2 hàng 2 cột
        {1, 2},   
        {3, 4}};

    int mang3chieu[2][2][2] = {       // 2 Khối, mỗi khối có 2 hàng, mỗi hàng có 2 cột        
    { {1, 2}, 
      {3, 4} },         // Khối 1
    
    { {5, 6},         // Khối 2
    {7, 8} }   
};    

// Xuất mảng 2 chiều
for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << i << ": " << j << ": " << mang2chieu[i][j] << endl;
        }
    } 

Terminal:
0: 0: 1
0: 1: 2
1: 0: 3
1: 1: 4

// Xuất mảng 3 chiều
for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
        for(int k = 0; k < 2; k++){
            cout << mang3chieu[i][j][k] << " ";           // 1 2 3 4 5 6 7 8
            }
        }
    }
}
                          Cách duyệt mảng 2 chiều mà không cần tự ghi kích thước của mảng ( 2 )

int row = sizeof(mang2chieu) / sizeof(mang2chieu[0]);            // Số hàng = Kích thước toàn mảng / Kích thước của 1 hàng
int colum = sizeof(mang2chieu[0]) / sizeof(mang2chieu[0][0]);   // Số Cột  = Kích thước của 1 hàng / Kích thước 1 phần tử nằm trong hàng