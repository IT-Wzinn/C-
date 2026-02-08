#include <iostream>
using namespace std;

// Hàm void không trả về giá trị, chỉ thực hiện hành động
void Xinchao() {
    cout << "Xin chào bạn đến với chương trình!" << endl;
}

// Hàm void có tham số
void Tinhtong(int a, int b) {
    cout << "Tổng của " << a << " và " << b << " là: " << a + b << endl;
}

// Hàm void truyền tham chiếu 
void Tanglen10(int &x) {
    x++;  // Tăng biến tại địa chỉ thực
}

int main(){
    Xinchao();

    Tinhtong(5, 10);

    int n = 7;
    cout << "Giá trị ban đầu của n: " << n << endl;
    Tanglen10(n);
    cout << "Sau khi gọi hàm tăng Lên Một: " << n << endl;

    return 0;
}
