                                                1. Các Lệnh Khai Báo Cơ Bản
int a;              
double b = 3.14;    
char c = 'A';       
string s = "Vinh";   
bool check = false;
const int MAX = 100;  


1.1 Khai Báo Mảng Tĩnh
int a1[3];                   
int a2[1000] = {0};          
int arr2D[10][20];           
int arr3D[2][2][2];         


1.2 Khai Báo Mảng Động
vector<int> v1;              
vector<int> v2(5);          
vector<int> v3(5, 10);       

int rows = 5, cols = 4;
vector<vector<int>> matrix(rows, vector<int>(cols, 0)); 


1.3 Deque
deque<int> d = {1, 2, 3};


1.4 Set
set<int> s;
s.insert(3);


1.5 Map
map<int, int> m;
m.insert({1,2});   
m[3] = 4;        
m[5];           // Nếu Key đó chưa có thì tự thêm Key đó với value = 0
a.at(key)      // Thường dùng để xem giá trị của value nếu chưa có key thì báo lỗi chứ không tạo value như a[key];        


1.6 Enum
enum a {
    nam,   // Tương đương 0
    vinh,  // Tương đương 1
    cuong  // Tương đương 2
};


1.7 Struct
struct Sinhvien{
    string name;
    int age;
};


1.8 Void
void Print(){
    cout << "Hello" << endl;
}


1.9 Iterator
auto it = find(v.begin(), v.end(), value);
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            2. Các Lệnh Xuất Giá Trị

// For truyền thống 
vector<int> a = {10, 20, 30};
for(int i = 0; i < a.size(); i++){
    cout << "Vị trí " << i << " có giá trị: " << a[i] << endl;
}

// Range Based For Loop
for (int i : a){
    cout << i << " ";
}
==> Chỉ dùng để ĐỌC, nếu thay đổi 'i' thì mảng gốc KHÔNG đổi. 

// Xuất giá trị của Set và Map bằng Iterator
set<int> s = {1, 2, 3, 4, 5};
for(auto it = s.begin(); it != s.end(); it++){
    cout << *it << " ";  
}
map<int, int> m;
for(auto it = m.begin(); it != m.end(); it++){
    cout << it->first << ": " << it->second << endl;  
}

// Xuất giá trị của Map bằng Range Based For Loop 
map<int, string> m = {{1, "One"}, {2, "Two"}};
for (auto i : m) {
    cout << i.first << ": " << i.second << endl;  
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                 3. Các Lệnh Đọc
// Gặp EOF là dùng  
vector<int> v;
int x;
while(cin >> x) {
    v.push_back(x);
}

// Nhập sẵn kích thước rồi mới nhập phần tử
int n;
cin >> n;
vector<int> v(n);
for(int i = 0; i < n; i++){
    cin >> v[i];
}

// Đọc bỏ qua khoảng trắng bằng sstream
string line;
getline(cin,line);

stringstream ss(line);
string s;

while(ss >> s){

}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                                                 THAM CHIẾU & CON TRỎ
                                            4. Tham chiếu, Con trỏ
void thamchieu(int &x){ x *= 2; }
void contro(int *x){ *x *= 2; }

int main(){
    int a = 2;
    thamchieu(a);
    contro(&a);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                              5. Thư Viện Algorithm
1. Nhóm Sắp xếp (Sorting)
sort(v.begin(), v.end());                      // Sắp xếp tăng dần
sort(v.begin(), v.end(), greater<int>());     // Sắp xếp giảm dần

bool cmp(int a, int b){return a > b;}                         }
sort(v.begin(), v.end(), cmp);                                }
                                                              }===> 2 sort này tương tự nhau về bản chất đều là sắp xếp từ lớn đến nhỏ
sort(v.begin(), v.end(), [](int a, int b){return a > b});     }

stable_sort(v.begin(), v.end());                                      // Giống sort nhưng giữ nguyên thứ tự tương đối của các phần tử có giá trị bằng nhau. ( Thường dùng cho container chứa cặp pair như vector, list )
partial_sort(v.begin(), v.begin()+3, v.end());                       // Sắp xếp 3 phần tử từ nhỏ nhất từ nhỏ đến lớn dãy phần tử còn lại là ngẫu nhiên
partial_sort(v.begin(), v.begin()+3, v.end(), greated<int>());      // Sắp xếp 3 phần tử từ lớn nhất đến nhỏ của dãy phần tử còn lại là ngẫu nhiên


2. Nhóm Tìm kiếm 
auto it = find(v.begin(), v.end(), value);                           // Tìm kiếm giá trị value trả về iterator trỏ đến vị trí đầu tiên tìm thấy
auto it = find_if(v.begin(), v.end(), [](int x){return > 5;});      // Tìm phần tử đầu tiên thỏa điều kiện

vector<int> a = {1,2,3,4,5,6};
vector<int> b = {3,4};
auto it = search(a.begin(), a.end(), b.begin(), b.end());

2.1 Nhóm Tìm Kiếm (Nhị Phân)
bool check = binary_search(v.begin(), v.end(), x);         // Kiểm tra xem x có tồn tại hay không (Trả về true/false)
auto it = lower_bound(v.begin(), v.end(), x);             // Trả về Iterator trỏ đến phần tử đầu tiên lớn hơn hoặc bằng x
auto it = upper_bound(v.begin(), v.end(), x);            // Trả về Iterator trỏ đến phần tử đầu tiên lớn hơn hẳn (>) x

// Distance
int vitri = distance(v.begin(), it);

3. Nhóm Đếm và Tính toán min/max
int k = count(v.begin(), v.end(), x);                                // Đếm số lần xuất hiện của một giá trị trong dãy.                   
int k = count_if(v.begin(), v.end(), [](int x){ return x > 5; });   // Đếm số phần tử thỏa một điều kiện (thường dùng lambda)
int min = min(v.begin(), v.end());                                 // Tìm phần tử nhỏ nhất giữa 2 phần tử
int max = max(v.begin(), v.end());                                // Tìm phần tử lớn nhất giữa 2 phần tử
int m = *max_element(v.begin(), v.end());                        // Trả về iterator trỏ đến phần tử lớn nhất trong dãy. Muốn lấy giá trị phải dùng *
int m = *min_element(v.begin(), v.end());                       // Trả về iterator trỏ đến phần tử nhỏ nhất trong dãy. Muốn lấy giá trị phải dùng *

4. Nhóm Thay đổi / Cập nhật chuỗi 
reverse(v.begin(), v.end());                                    // Đảo ngược thứ tự các phần tử trong dãy.
replace(v.begin(), v.end(), old_value, new_value);             // Thay thế mọi phần tử có giá trị old_value thành new_value.
fill(v.begin(), v.end(), value);                              // Gán toàn bộ phần tử trong khoảng bằng một giá trị.
swap(a, b);                                                  // Hoán đổi giá trị của hai biến.
v.erase(remove(v.begin(), v.end(), val), v.end());          // Đẩy các phần tử khác value lên đầu dãy và trả iterator về sau phần tử cuối dãy các phần tử còn lại là đều biến thành rác (erase xóa các phần tử rác còn lại từ it đến hết).
v.erase(unique(v.begin(), v.end()), v.end());              // Phải sort trước rồi unique sẽ xóa các phần tử trùng lặp liên tiếp (erase sẽ xóa các phần tử rác phía sau).


/* 
| Phân loại cốt lõi               | Nhóm "Ăn liền" (Thư viện STL C++ có sẵn)                         | Nhóm "Thủ công" (Tự định nghĩa trong LeetCode) |
| ------------------------------- | ---------------------------------------------------------------- | ---------------------------------------------- |
|   Tuyến tính (Linear)           |  vector ,  string ,  stack ,  queue ,  deque                     |   Linked List   (Danh sách liên kết)           |
|   Phi tuyến tính (Non-linear)   |  map ,  set ,  unordered_map ,  unordered_set ,  priority_queue  |   Trees   (Cây),   Graphs   (Đồ thị)           |
*/           