#include <iostream>
using namespace std;

void updatevalue (int *i){
    *i = *i * 2;
}

int main(){
    int a = 10;
    int &b = a;  // &: Biến b thành cách gọi khác của a
    int *ptr = &a; // Con trỏ: Biến ptr là 1 biến khác có chức năng lưu địa chỉ của biến a

    cout << "Địa chỉ của a: " << &a << endl;
    cout << "Giá trị của a: " << a << endl;
    

    cout << "Địa chỉ của b: " << &b << endl;  // Giống với a vì b là tham chiếu của a 
    cout << "Giá trị của b: " << b << endl;      // Giống với a vì b là tên gọi khác của a 
    
    cout << "Địa chỉ của a bằng con trỏ: " <<  ptr << endl;
    cout << "Giá trị của a bằng con trỏ: " << *ptr << endl;
    cout << "Địa chỉ của ptr: " << &ptr << endl;  // Khác với a, vì ptr là 1 biến khác riêng biệt chứ không như b


    //Tăng giá trị của biến gốc a bằng Con trỏ
    updatevalue( &a );
    cout << "Sau khi tăng: " << a << endl;

    // Tăng mảng bằng tham chiếu
    int arr[] = {1, 2, 3, 4, 5};
    
    for(int &n : arr){  
        n *= 2;                   // Nhân đôi tất cả phần tử 
    }

    for(int i : arr){
        cout << i << " ";         // Kết quả: 2 4 6 8 10
    }

return 0;
}
//======================================================================================================================================================================================================================================================================
                                           LƯU Ý

Tham chiếu ( Reference ) tác động trực tiếp lên biến gốc, mọi thay đổi qua tham chiếu sẽ làm thay đổi giá trị của biến gốc.
Tham trị  ( Pass by value ) tạo ra một bản sao (biến ảo), thay đổi trên bản sao không ảnh hưởng đến biến gốc.
Tóm lại:
Tham chiếu không tạo biến ảo, mà thao tác trực tiếp lên biến thật
updateValue(&a); → Truyền địa chỉ của a vào hàm, i sẽ trỏ đến.


                                        Truyền tham trị                        
void tang(int x) {
    x++;
    cout << "Trong hàm: " << x << endl;
}

int main() {
    int a = 5;
    tang(a);    //6
    cout << "Ngoài hàm: " << a << endl;   //5
}
   

                                  Truyền tham chiếu và Con trỏ
void thamchieu(int &x) {
    x = 100;
}

void contro(int *x) {
    *x = 100;
}

int main() {
    int a = 5;
    thamchieu(a);  // a = 100
    contro(&a);   // a = 100
}
/*
Kết luận: 
==> Tham chiếu: Thêm 1 dấu & khi khai báo (int &x)
==> Con trỏ: Khi khai báo thì phải có dấu * (*i) khi truyền biến để tham chiếu vào thì phải truyền địa chỉ (&a)

Tham chiếu: “bí danh” cố định, không đổi, không null, cú pháp đơn giản.
Con trỏ: có thể đổi chỗ trỏ, có thể null, cú pháp phức tạp hơn.
*/