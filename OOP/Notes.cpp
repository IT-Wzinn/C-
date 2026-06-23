1. Đóng gói:
_ Giấu thuộc tính của đối tượng lại trong khu private chỉ có hàm thuộc class mới có thể truy cập hoặc chỉnh sửa thuộc tính đó được.
_ Hàm bạn cũng có thể truy cập cũng như là thay đổi được các thuộc tính private nếu được class mời.
_ protected là khu vực chứa các thuộc tính mà lớp con có thể kế thừa từ lớp cha. 

2. Kế thừa
_ Được kế thừa sẵn các thuộc tính ( nằm trong phạm vi protected ) và các hàm của lớp cha.

3. Đa hình
_ Ghi đè / thay đổi các hàm có sẵn từ lớp cha.
_ Hàm virtual là hàm cho phép lớp con ghi đè, override ở lớp con có tác dụng kiểm tra xem có đang ghi đè đúng hàm virtual ở trên lớp cha hay không.
_ Nếu lớp cha có 1 hàm virtual thì hàm hủy destructer cũng phải virtual theo vì nếu thiếu virtual ở destructer thì 
khi giải phóng bộ nhớ của bằng con trỏ của lớp cha thì destructer của lớp con sẽ bị bỏ qua và không chạy gây rò gĩ bộ nhớ.

4. Trừu tượng
_ Viết một hàm trừu tượng = 0 có tác dụng cam kết các lớp con cũng phải có hàm trừu tượng đó nhiệm vụ thay đổi nguyên lí hoạt động bên trong 
của mỗi class con sẽ được do Đa hình xử lí 



                                            Khai báo Class bằng cấp phát động OOP:
1. Dùng con trỏ thuần:

    vector<TaiKhoan*> danhSachThe;
    danhSachThe.push_back(new TaiKhoanThuong("111222", "Nguyen Van A", 50000));
    danhSachThe.push_back(new TaiKhoanTinDung("999888", "Tran Thi B", 10000, 500000));

_ Ưu điểm: Hiểu rõ cơ chế new và delete.
_ Nhược điểm: Bạn phải tự tay delete từng phần tử. Nếu quên, chương trình sẽ bị rò rỉ bộ nhớ (Memory Leak).


2. Dùng Smart Pointers (std::unique_ptr) - Cách thông dụng nhất hiện nay
    #include <memory> // Thư viện để dùng smart pointer

    vector<unique_ptr<NhanVien>> danhSachNV;
    danhSachNV.push_back(make_unique<Dev>("Nguyen Van A"));
    danhSachNV.push_back(make_unique<Sales>("Tran Thi B"));

_ KHÔNG CẦN VÒNG LẶP DELETE, C++ tự lo hết!


3. Tại sao chúng ta KHÔNG THỂ dùng vector<NhanVien> danhSachNV; ?
_ Bạn có thể tự hỏi: "Tại sao không tạo một vector chứa trực tiếp đối tượng luôn cho khỏe?"
_ Lý do: Đây là lỗi Object Slicing (Gọt tỉa đối tượng).
_ Hậu quả: vector<NhanVien> chỉ dành ra những ô nhớ vừa đủ cho lớp cha. Khi bạn cố nhét một Dev (có thêm thuộc tính ngonNgu) vào, 
C++ sẽ cắt bỏ hết phần riêng của Dev để nhét vừa vào ô của NhanVien. Lúc này, tính Đa hình biến mất hoàn toàn, gọi lamViec() sẽ chỉ ra kết quả của lớp cha.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                1. Tính Đóng Gói (Encapsulation)

Ví dụ: Quản lý số dư tài khoản. Bạn không thể tự tiện sửa số dư bằng cách gán soDu = 1 tỷ, mà phải thông qua hàm napTien().

class TaiKhoan {
private:
    double soDu; // Bị giấu kín, bên ngoài không thể truy cập trực tiếp

public:
    void napTien(double tien) {
        if (tien > 0) soDu += tien; // Chỉ cho phép thay đổi nếu dữ liệu hợp lệ
    }
    double getSoDu() const { return soDu; } // Chỉ cho xem, không cho sửa
};

==> Cốt lõi: Bảo vệ dữ liệu khỏi bị thay đổi trái phép hoặc sai logic.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                2. Tính Kế Thừa (Inheritance)

Ví dụ: Lớp cha là Điện thoại, lớp con là Smartphone. Smartphone không cần định nghĩa lại việc "Nghe/Gọi" vì nó đã có sẵn từ lớp cha.

class DienThoai {
public:
    void nghe() { cout << "Dang nghe..."; }
    void goi() { cout << "Dang goi..."; }
};

class SmartPhone : public DienThoai { // Kế thừa từ DienThoai
public:
    void luotWeb() { cout << "Dang luot web..."; } // Thêm tính năng mới
};

==> Cốt lõi: Tránh lặp lại code. SmartPhone tự động có tính năng nghe, gọi mà không cần viết lại.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                3. Tính Đa Hình (Polymorphism)

Ví dụ: Cùng là hành động moKhoa(), nhưng với điện thoại cũ là bấm phím, với máy đời mới là quét vân tay hoặc khuôn mặt.

class DienThoai {
public:
    virtual void moKhoa() { cout << "Mo khoa bang phim." << endl; }
};

class FaceIDPhone : public DienThoai {
public:
    void moKhoa() override { cout << "Mo khoa bang khuon mat." << endl; } // Ghi đè (Overriding)
};

// Sử dụng:
DienThoai* dt = new FaceIDPhone();
dt->moKhoa(); // Kết quả: Mo khoa bang khuon mat (Dù dùng danh nghĩa lớp cha)

==> Cốt lõi: Một cái tên (moKhoa), nhiều cách thực hiện tùy vào đối tượng thực tế.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                4. Tính Trừu Tượng (Abstraction)

Ví dụ: Bạn thiết kế một cái Điều khiển (Remote). Remote chỉ có nút bat(), tat(). Bạn không cần biết bên trong cái TV đó dùng bóng đèn LED hay OLED.

class ThietBiDien { // Lớp trừu tượng
public:
    virtual void bat() = 0; // Hàm ảo thuần túy: Chỉ đưa ra khái niệm
    virtual void tat() = 0;
};

class Quat : public ThietBiDien {
public:
    void bat() override { cout << "Quat quay..."; } // Cài đặt chi tiết tại đây
    void tat() override { cout << "Quat dung..."; }
};

==> Cốt lõi: Giúp người dùng tập trung vào "làm cái gì" (bat/tat) thay vì "làm như thế nào" (chi tiết kỹ thuật bên trong).
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Quy Tắc OOP

void Setname(const string &n): Truyền tham chiếu + không cho sửa giá trị của tham số.
const string &Getname() const{}: Const đầu không cho sửa dữ liệu trả về, Const sau không cho thay đổi thuộc tính của oject

// Initializer List
Sinhvien() : name("Unknown") {}
Sinhvien(const string &n) : name(n) {}

--> Kết luận: Khởi tạo Contructer bằng Initializer list sẽ không cần có bước khởi tạo string mà được gán THẲNG bằng Unknown luôn nên sẽ nhanh hơn cách này
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// this 
class Student {
public:
    int age;

    void setAge(int age){
        this->age = age;
    }
}
==> this-age ở đây là ám chỉ Thuộc Tính age của class để phân biệt với Tham số age được truyền vào
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Destructer
Nếu một class có hàm virtual thì thường class đó sẽ được dùng qua con trỏ class cha (Đa hình).
Nếu destructor không virtual, khi delete qua con trỏ cha thì destructor của class con sẽ không chạy -→ Gây rò rỉ bộ nhớ hoặc lỗi tài nguyên.

Class cha
class Base {
public:
    ~Base() {
        cout << "Base destructor\n";
    }
};

Class con
class Derived : public Base {
public:
    int* data;

    Derived() {
        data = new int[100];
    }

    ~Derived() {
        cout << "Derived destructor\n";
        delete[] data;
    }
};

Tình huống nguy hiểm:
Base* obj = new Derived();
delete obj;

Kết quả terminal hiện: Base destructor
==> Destructor của Derived bị bỏ qua → delete[] data không chạy → Memory leak.

Cách đúng: Destructor của class cha phải virtual.
class Base{
public:
    virtual ~Base() {
        cout << "Base destructor\n";
    }
};