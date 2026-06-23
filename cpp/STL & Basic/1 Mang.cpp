#include <iostream>
#include <vector>
#include <algorithm> // Thư viện chứa hầu hết các hàm xử lý mảng
#include <numeric>   // THÊM MỚI: Thư viện chứa các hàm toán học (accumulate, iota...)

using namespace std;

int main() {
    vector<int> v = {1, 5, 2, 8, 5, 9, 3};
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 3, 4};
    int x = 5;  

    // ==========================================
    // 1. NHÓM SẮP XẾP (SORTING)
    // ==========================================
    sort(v.begin(), v.end());                                  // Sắp xếp tăng dần: 1 2 3 5 5 8 9
    sort(v.begin(), v.end(), greater<int>());                  // Sắp xếp giảm dần: 9 8 5 5 3 2 1
    
    // Dùng hàm lambda để tự định nghĩa luật sắp xếp (Ví dụ: ưu tiên số chẵn lên đầu)
    sort(v.begin(), v.end(), [](int a, int b) { 
        if (a % 2 == 0 && b % 2 != 0) return true; 
        return a < b; 
    });

    stable_sort(v.begin(), v.end());                           // Sắp xếp giữ nguyên thứ tự tương đối của các phần tử bằng nhau
    partial_sort(v.begin(), v.begin() + 3, v.end());           // Chỉ lấy 3 phần tử nhỏ nhất đưa lên đầu, phần còn lại thứ tự ngẫu nhiên

    // ==========================================
    // 2. NHÓM TÌM KIẾM (SEARCHING)
    // ==========================================
    // 2.1 Tìm kiếm tuyến tính O(N)
    auto it1 = find(v.begin(), v.end(), x);                    // Trả về iterator trỏ đến x đầu tiên. Nếu không thấy trả về v.end()
    auto it2 = find_if(v.begin(), v.end(), [](int val){ return val > 5; }); // Tìm phần tử đầu tiên thỏa điều kiện (> 5)
    auto it3 = search(v.begin(), v.end(), a.begin(), a.end()); // Tìm mảng con 'a' xuất hiện bên trong mảng 'v'

    // 2.2 Tìm kiếm nhị phân O(log N) - MẢNG PHẢI ĐƯỢC SẮP XẾP TRƯỚC
    sort(v.begin(), v.end());
    bool check = binary_search(v.begin(), v.end(), x);         // Kiểm tra xem x có tồn tại không (True/False)
    auto it_lb = lower_bound(v.begin(), v.end(), x);           // Trả về iterator của phần tử đầu tiên >= x
    auto it_ub = upper_bound(v.begin(), v.end(), x);           // Trả về iterator của phần tử đầu tiên > x (lớn hơn hẳn)
    int vitri = distance(v.begin(), it_lb);                    // Quy đổi từ iterator ra chỉ số (index)

    // ==========================================
    // 3. NHÓM ĐẾM, MIN/MAX & TOÁN HỌC (THƯỜNG XUYÊN BỊ QUÊN)
    // ==========================================
    int k1 = count(v.begin(), v.end(), x);                     // Đếm số lần x xuất hiện trong mảng
    int k2 = count_if(v.begin(), v.end(), [](int val){ return val % 2 == 0; }); // Đếm số chẵn

    int m_max = *max_element(v.begin(), v.end());              // Lấy GIÁ TRỊ lớn nhất (thêm dấu * để giải tham chiếu)
    int m_min = *min_element(v.begin(), v.end());              // Lấy GIÁ TRỊ nhỏ nhất

    // -- THÊM MỚI (Cần thư viện <numeric>) --
    // Tính tổng toàn bộ mảng. Số '0' ở cuối là giá trị khởi tạo của tổng.
    long long tong = accumulate(v.begin(), v.end(), 0LL);      
    
    // Điền mảng với các giá trị tăng dần (VD: 0, 1, 2, 3...) - Cực kỳ hữu dụng để khởi tạo mảng index
    iota(v.begin(), v.end(), 0);                               

    // ==========================================
    // 4. NHÓM KIỂM TRA ĐIỀU KIỆN (BỔ SUNG - RẤT HỮU ÍCH)
    // ==========================================
    // Cả 3 hàm này đều trả về True/False. Rất hay dùng trong Leetcode để né viết vòng lặp for
    bool all_even = all_of(v.begin(), v.end(), [](int val){ return val % 2 == 0; }); // True nếu TẤT CẢ là số chẵn
    bool has_even = any_of(v.begin(), v.end(), [](int val){ return val % 2 == 0; }); // True nếu CÓ ÍT NHẤT 1 số chẵn
    bool no_even  = none_of(v.begin(), v.end(), [](int val){ return val % 2 == 0; }); // True nếu KHÔNG CÓ số chẵn nào

    // ==========================================
    // 5. NHÓM THAY ĐỔI / CẬP NHẬT MẢNG (MODIFYING)
    // ==========================================
    reverse(v.begin(), v.end());                               // Đảo ngược mảng
    fill(v.begin(), v.end(), 0);                               // Gán toàn bộ mảng bằng 0
    replace(v.begin(), v.end(), 5, 99);                        // Thay toàn bộ số 5 thành 99

    // Xóa phần tử (Idiom: Erase-Remove)
    v.erase(remove(v.begin(), v.end(), x), v.end());           // Xóa tất cả các phần tử có giá trị là x
    
    // Lọc trùng (Chỉ giữ lại các phần tử duy nhất) - MẢNG PHẢI ĐƯỢC SORT TRƯỚC
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());              

    // -- THÊM MỚI --
    // Xoay mảng: Đưa k phần tử đầu tiên xuống cuối mảng. Bài Leetcode "Rotate Array" chỉ cần 1 dòng này!
    int k_rotate = 2;
    rotate(v.begin(), v.begin() + k_rotate, v.end());          
    
    // Map dữ liệu: Áp dụng một phép toán lên toàn bộ mảng (Ví dụ: Bình phương mọi phần tử)
    transform(v.begin(), v.end(), v.begin(), [](int val){ return val * val; });

    // ==========================================
    // 6. NHÓM TẬP HỢP (SETS) & HOÁN VỊ (PERMUTATIONS) (BỔ SUNG)
    // ==========================================
    // Sinh hoán vị (Rất hay gặp trong bài toán sinh dãy, Backtracking)
    vector<int> perm = {1, 2, 3};
    next_permutation(perm.begin(), perm.end());                // Biến đổi perm thành hoán vị kế tiếp: {1, 3, 2}
    prev_permutation(perm.begin(), perm.end());                // Trở về hoán vị trước đó

    // Các phép toán giao/hợp (MẢNG PHẢI ĐƯỢC SORT TRƯỚC)
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> result(a.size() + b.size());
    
    // Lấy phần giao (Intersection) của a và b
    auto it_set = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(it_set - result.begin());                    // Cắt bỏ phần rác thừa của result

    return 0;
}