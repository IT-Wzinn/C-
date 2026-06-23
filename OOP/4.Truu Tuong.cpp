#include <iostream>
#include <string>

using namespace std;

// ==========================================
// --- LỚP TRỪU TƯỢNG (Interface / Khung chuẩn) ---
// Đóng vai trò là cái "Mặt ngoài" của Máy pha cà phê
// ==========================================
class MayPhaCaPhe {
public:
    virtual ~MayPhaCaPhe() {}

    // TÍNH TRỪU TƯỢNG: Hàm ảo thuần túy (= 0)
    // Máy chung chung thì không biết pha kiểu gì, nên chỉ tạo cái "nút bấm" để đó.
    // Lớp con BẮT BUỘC phải tự định nghĩa lại hành động này.
    virtual void phaCaPhe() = 0; 
};

// ==========================================
// --- LỚP CON 1: Máy pha Espresso ---
// ==========================================
class MayEspresso : public MayPhaCaPhe {
private:
    // Chi tiết kỹ thuật phức tạp BỊ GIẤU KÍN bên trong
    void xayHat() { cout << "   + Xay hat ca phe sieu min..." << endl; }
    void nenApSuat() { cout << "   + Nen ap suat cao 15 bar..." << endl; }
    void chietXuat() { cout << "   + Chiet xuat 30ml Espresso dam dac!" << endl; }

public:
    // Thực thi "bản hợp đồng" từ lớp cha
    void phaCaPhe() override {
        cout << "-> Dang pha ESPRESSO:" << endl;
        xayHat();
        nenApSuat();
        chietXuat();
        cout << "=> Hoan thanh ly Espresso!\n" << endl;
    }
};

// ==========================================
// --- LỚP CON 2: Máy pha Cà phê Phin ---
// ==========================================
class MayPhaPhin : public MayPhaCaPhe {
private:
    // Chi tiết kỹ thuật hoàn toàn khác biệt so với Espresso
    void uCaPhe() { cout << "   + U ca phe voi it nuoc soi trong 2 phut..." << endl; }
    void chamNuoc() { cout << "   + Cham them nuoc va doi nho giot..." << endl; }

public:
    void phaCaPhe() override {
        cout << "-> Dang pha CA PHE PHIN:" << endl;
        uCaPhe();
        chamNuoc();
        cout << "=> Hoan thanh ly Ca phe Phin!\n" << endl;
    }
};

// ==========================================
// PHẦN VẬN HÀNH (Hàm Main - Vai trò Khách hàng)
// ==========================================
int main() {
    cout << "--- TÍNH TRỪU TƯỢNG TRONG OOP ---\n" << endl;

    // LỖI: Bạn KHÔNG THỂ khởi tạo một "Máy pha cà phê chung chung"
    // MayPhaCaPhe mayChung; -> Lỗi biên dịch ngay lập tức!

    // Dùng CON TRỎ LỚP CHA để thể hiện sự trừu tượng tối đa:
    // "Tôi chỉ cần biết đây là một cái máy pha cà phê (MayPhaCaPhe*), 
    // tôi không cần quan tâm tên thật của nó là gì."
    MayPhaCaPhe* may1 = new MayEspresso();
    MayPhaCaPhe* may2 = new MayPhaPhin();

    // Khách hàng CHỈ SỬ DỤNG MỘT NÚT BẤM DUY NHẤT: phaCaPhe()
    // Toàn bộ quy trình xay, nén, ủ nước đã bị giấu hoàn toàn!
    may1->phaCaPhe(); 
    may2->phaCaPhe();

    // Dọn dẹp
    delete may1;
    delete may2;

    return 0;
}