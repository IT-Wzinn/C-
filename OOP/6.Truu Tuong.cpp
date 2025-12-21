#include <iostream>
using namespace std;

class Thanhtoan{                                // Lớp trừu tượng
public: 
    virtual void Tratien(int sotien) = 0;      // Hàm thuần ảo (=0): Bắt buột lớp con phải có hàm Tratien nếu không thì không chạy được
};

class Tienmat : public Thanhtoan{
public:     
    void Tratien(int sotien) override{                                      // override để kiểm tra
        cout << "Đang trả tiền bằng tiền mặt: " << sotien << endl;
    }
};

class Thenganhang : public Thanhtoan{
public:     
    void Tratien(int sotien) override{
        cout << "Đang trả tiền bằng thẻ ngân hàng: " << sotien << endl;
    }
};

void Xulitratien(Thanhtoan* a){
    a->Tratien(100);
}

int main(){

    Thanhtoan* a = new Tienmat();
    Xulitratien(a);

    Thanhtoan* b = new Thenganhang();
    Xulitratien(b);
}

/*                                                 Trừu tượng

_ Tạo ra một hàm thuần ảo thay vì định nghĩa {} thành = 0, và bắt buột lớp con phải override thì chương trình mới được phép chạy 
==> Mọi lớp con muốn tạo object -→ bắt buộc phải override hàm thuần ảo

_ Không được tạo đối tượng từ lớp trừu tượng vì mọi hàm trong lớp đều phải hoàn chỉnh thì mới cho phép tạo đối tượng được còn lớp trừu tượng thì không làm thế được vì có hàm thuần ảo

_ Chọn Tratien là hàm thuần ảo vì mọi hình thức thanh toán bắt buộc phải có hành vi “Trả tiền” ( Trừu tượng ), nhưng cách trả thì khác nhau ( Đa hình )

*/