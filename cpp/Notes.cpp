                                                                          Notes C++
1) Form 

1.1) 
if(){

}

else if(){

}

else{ 

}

1.2)
for(){

}

1.3)
while(){

}

1.4)
void(){

}

1.5)
struct{

};

1.6)
switch(){
case ' ':
    break;

default:
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2) Ép kiểu
cout << double(a) / b;   ✅     Thực / Nguyên --> Thực
cout << double (a / b);  ❌     double(Nguyên / Nguyên) --> Nguyên,0
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3) Range based for loop
for (int i : a) {
    cout << i << " ";
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4) Enum
enum a{
    nam, // 0
    vinh,  // 1
    cuong   // 2
};
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
5) Toán tử 3 ngôi 
string dapan - (1 < 2) ? "True" : "False";   
cout << dapan;


Nếu viết tắt trong hàm thì có thể viết như này: 
int min(int x, int y) {
    return (x < y) ? x : y;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
6) Hằng số
const int a - 10;

6.1) Size
string a - "Vinh";
cout << "Kích thước của chuỗi a: " << sizeof(a);           //34
cout << "Số lượng phần tử trong chuỗi a: " <<  a.size();     //4  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
7) Nhập kích thước của Mảng xong rồi nhập các phần tử của mảng khi đủ số lượng phần tử của mảng thì tự ngừng ( Xuống dòng hay cùng dòng đều được )

// Cấp Phát Động
int n;
cin >> n;

int* a = new int[n];

for(int i = 0; i < n; i++){
    cin >> a[i];
}

delete[] a;

// Vector
int n;
cin >> n;

vector<int> a(n);

for(int i = 0; i < n; i++){
    cin >> a[i];
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
8) Nhập phần tử liên tục ( Cùng hàng, gặp Enter là DỪNG ) 

    #include <sstream>

    string line;
    getline(cin, line);

    stringstream ss(line);
    int s;                   // Tùy theo dạng dữ liệu muốn truyền vào             

    while(ss >> s) { 
       
    }
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
9) cin.ignore(); vs getline(cin >> ws, name);

--> cin.ignore(): Chỉ xóa 1 ký tự trước đó
--> getline(cin >> ws, name): Xóa toàn bộ khoảng trắng trước đó

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
10) Ước chung lớn nhất và Bội chung nhỏ nhất

#include <algorithm>
int gcd -  __gcd(a, b); 
int lcm - (a * b) / __gcd(a, b);

cout << "Ước chung lớn nhất: " << gcd << endl;
cout << "Bội chung nhỏ nhất: " << lcm << endl;
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
11) Kiểm tra vector rỗng 

if (v.empty()) cout << "Vector Rỗng";
else cout << "Vector Không Rỗng";
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
12) 

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
13) Số nguyên nhỏ nhất và số nguyên lớn nhất
#include <climits>
int min - INT_MIN;
int max - INT_MAX;

13.1) *p++
Viết thế này:            Thực chất là:                       Tác động:
*p++                       *(p++)                   Dời con trỏ p sang phần tử kế tiếp
(*p)++                     (*p)++                   Tăng giá trị tại ô p đang trỏ tới 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
14)                                             Các Loại Mảng Thường Sử Dụng
int a[];            
int a[n] - {};     

vector<int> v;               
vector<int> v(n);            
vector<int> v(n, 5);       

                                                       Các Loại Nhập
1) Nhập n phần tử của mảng trước 
int n;
cin >> n;
int mang[n];    Hoặc    vector<int> v(n);  
     
for(int i - 0; i < n; i++){
cin >> v[i];
}

2) Nhập thẳng các phần tử cách nhau bởi xuống dòng chứ không nhập trước số lượng phần tử   ( Ngừng khi gặp EOF )
vector<int> v;
int x;

while(cin >> x){
    v.push_back(x); 
}

3) Nhập các phần tử cách nhau bởi dấu cách trên cùng 1 hàng
string line;
getline(cin, line);

stringstream ss(line);
int n;

while(ss >> n){
    v.push_back(n);
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
15)                                       Tham chiếu và Con trỏ 
void Thamchieu(int &x){
    x - 100;
}

void Contro(int *x){ 
    *x - 100;
}

int main(){
    int b - 5;
    Thamchieu(b);                // b - 100
    Contro(&b);                 // b - 100
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
19) Mảng bool
    int mang[100];
    bool dadem[100] - {false};                      // Toàn bộ 100 phần tử của đã damdem đều có giá trị false
    --> Có thể dùng để đánh dấu vị trí của mảng 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
20)              Thư viện

    #include <iomanip> --> fixed, setprecision,...
    #include <cmath> --> pow, sqrt, cbrt, ceil, floor, round, abs, fabs,...
    #include <algorithm> -->  sort, reverse, find, count, max_element(), min_element(),...
    #include <sstream> --> stringstream,...
    #include <climits> --> INT_MIN, INT_MAX,...
    #include <iterator> --> distance();
    
               *Thư viện cmath 

    1	pow(x, y)              Trả về x mũ y
    2	sqrt(x)	           Trả về căn bậc 2 của x
    3	cbrt(x)	           Trả về căn bậc 3 của x
    4	ceil(x)	               Làm tròn lên
    5	floor(x)              Làm tròn xuống
    6	round(x)            Làm tròn bình thường (>-5)
    7   abs(x)	             Trị tuyệt đối (int)	
    8	fabs(x)	         Trị tuyệt đối ( double, float )
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                      Thư viện algorithm 

 Hàm	                   Tác dụng	                             Cú pháp

sort()	                Sắp xếp tăng dần 	             sort(a.begin(), a.end());
reverse()	              Đảo ngược              	  reverse(s.begin(), s.end());
max_element()	  Trả iterator phần tử lớn nhất	     max_element(a.begin(), a.end());
min_element()	 Tương tự, trả phần tử nhỏ nhất	     min_element(a.begin(), a.end());
count()         Đếm số lần xuất hiện của phần tử	  count(s.begin(), s.end(), 'a');
find()	       Tìm phần tử đầu tiên có giá trị x	  find(a.begin(), a.end(), x);
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
21) Sự khác nhau giữa 2 cách duyệt 1 chuỗi ( For đọc được từng kí tự kể cả " " ) còn ( While thì bỏ " " để đọc phần tử )

| Đặc điểm           | for (char c : s)                                        | while (ss >> x)                               |
| ------------------ | --------------------------------------------------------|---------------------------------------------  |
| 💡 Dùng để         | Duyệt từng ký tự trong chuỗi string                     | Đọc từng từ hoặc số từ stringstream           |
| 🔍 Dữ liệu duyệt   | Từng ký tự trong string                                 | Từng phân đoạn tách bằng khoảng trắng         |
| 📦 Loại dữ liệu    | char                                                    | string, int, v.v. (tùy mục đích dùng)         |
| 🧠 Cách dùng       | for (char c : s)                                        | stringstream ss(s); while (ss >> word)        |
| 📌 Tình huống dùng | Kiểm tra từng ký tự, ví dụ: xóa dấu cách, đếm chữ cái...| Đọc từng từ hoặc số từ input dòng             |
| 🛠️ Ví dụ dùng      | Xóa khoảng trắng trong chuỗi                            | Tính tổng các số nhập từ 1 dòng               |

--> Lưu ý: Cách while bỏ qua khoảng trắng còn for(char c : s) đọc được khoảng trắng 
nên sẽ mạnh về khoảng duyệt mọi kí tự trong chuỗi hơn còn while sẽ mạnh về duyệt từng phần tử hơn

--> for (range based for loop) đọc được khoảng trắng còn while (sstream) thì không
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
22) Viết ngược ( Reverse áp dụng được cho cả string, array, vector, deque,...)
   
    reverse(a.begin(), a.end());
    for(string s : a){
    cout << s << " ";               --> Viết ngược mảng 
    }

    vector<string> a;   
    for(string s : a){
    reverse(s.begin(), s.end());        --> Viết ngược phần tử bên trong 
        cout << s << " ";
    }
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
23)                                       Max, Min, Count, Find, Distance Trong Container  

vector<int> a - {1,2,3,4,5,2,2,3,4,4,4};

1) Phần tử lớn nhất trong Container.
auto it - max_element(a.begin(), a.end());            

2) Phần tử nhỏ nhất trong Container.
auto it - min_element(a.begin(), a.end());                

3) Trỏ it đến phần tử mình muốn tìm 
auto it - find(a.begin(), a.end(), 2);      

                                        Vị trí và số lượng phần tử trong Container

1) Vị trí của phần tử mình muốn tìm.
int index - distance(a.begin(), it);                        

2) Đếm số lượng của phần tử mình muốn biết trong Container xem nó có số lượng bao nhiêu.
int a - count(v.begin(), v.end(), 2);

Lí Thuyết:
_ *it chỉ để biểu diễn giá trị
_ it là vị trí của iterator tại đó, sài cho mọi trường hợp trừ xuất giá trị 
_ a.begin()/ a.end() cũng là một loại con trỏ nên it mới có thể so sánh với chúng 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
24) Xóa phần tử của String 
                                          Substr/ Erase 
insert ( Chèn )
s.insert(it, n, 'a')     : Chèn n ký tự 'a' TRƯỚC iterator it
s.insert(pos, "abc")     : Chèn "abc" vào trước kí tự pos  

erase   ( XÓA )
s.erase(pos)          : Xóa từ pos đến hết chuỗi tính luôn cả pos
s.erase(pos, len)     : Xóa len ký tự từ pos tính luôn cả pos 
s.erase(it)           : Xóa phần tử iterator it trỏ tới 
s.erase(it1, it2)     : Xóa toàn bộ đoạn [it1, it2)

substr  ( LẤY )
s.substr(pos)        : Lấy từ pos đến hết chuỗi  
s.substr(pos, len)   : Lấy len ký tự từ pos

replace (THAY THẾ)                 
s.replace(pos, len, "abc")         : Xóa len ký tự tại pos rồi chèn "abc"
s.replace(it1, it2, "abc")         : Thay đoạn [it1, it2) bằng "abc"

LƯU Ý: 
String dùng được : insert, erase, substr, replae 
Container dùng được : insert, erase 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                Vector
| Hàm thành viên          | Mục đích                                          | Ví dụ ngắn                                 |
|-------------------------|---------------------------------------------------|--------------------------------------------|
| size() / length()       | Trả về độ dài chuỗi                               | s.size() hoặc s.length()                   |
| empty()                 | Kiểm tra chuỗi có rỗng hay không                  | s.empty()                                  |
| clear()                 | Xóa hết nội dung chuỗi                            | s.clear()                                  |
| push_back               | Thêm ký tự  c  vào cuối chuỗi                     | s.push_back('a')                           |
| pop_back()              | Xóa ký tự cuối cùng của chuỗi                     | s.pop_back()                               |
| push_front()            | Thêm kí tự vào đầu                                | s.push_back()                              |
| pop_front()             | Xóa kí tự đầu                                     | s.pop_back()                               |
| substr(pos, len)        | Trích xuất chuỗi con bắt đầu tại  pos , dài len   | s.substr(2, 4) → lấy 4 ký tự từ vị trí 2   |
| find(str)               | Tìm vị trí xuất hiện đầu tiên của chuỗi str       | s.find("abc")                              |
| replace(pos, len, str)  | Thay thế phần chuỗi từ  pos , độ dài  len  bằng chuỗi  str  | s.replace(1, 3, "xyz")           |
| insert(pos, str)        | Chèn chuỗi  str  vào vị trí  pos                  | s.insert(2, "hello")                       |
| erase(pos, len)         | Xóa phần chuỗi từ  pos , dài  len                 | s.erase(1, 3)                              |
| compare(str)            | So sánh chuỗi với chuỗi khác                      | s.compare("abc")                           |
| at(pos)                 | Truy cập ký tự tại vị trí  pos                    | char c - s.at(0)                           |

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
25) Lưu ý về Range for based loop for(char c : s){}

for(char c : s) trong C++ là duyệt theo kiểu tham trị ( Pass by value ).
Nghĩa là biến c chỉ là một bản sao của từng ký tự trong chuỗi s
Khi bạn thay đổi c, chuỗi gốc s không bị ảnh hưởng.
--> Nếu muốn thì phải thêm &: for(char &c : s){}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
***                                             Trick lord
#include <bits/stdc++.h>

In thường, in Hoa, max_element
s[i] - toupper(s[i]) : Chuyển kí tự thành chữ HOA
s[i] - tolower(s[i]) : Chuyển kí tự thành chữ THƯỜNG 

if(isupper(s[i])) : Kiểm tra phải chữ Hoa không
if(islower(s[i])) : Kiểm tra phải chữ Thường không



* Xuất các đáp án true false thành chữ thay vì số 0 1 thì sài cout << boolalpha << 
* Định dạng đầu ra số thập phân << fixed << setprecision();
* Nếu muốn xử lí sâuuu các phần tử của stringstream thì có thể push_back từng phần đó vào một VECTOR rồi xử lí 



vector<int> a - {1,2,3,4,5,2,2,3,4,4,4};
1) Max_element trả về iterator vị trí của phần tử lớn nhất
auto it - max_element(a.begin(), a.end());               
cout << "Phần tử lớn nhất là: " << *it;                
                             
                               1.1) Find trả về iterator trỏ tới vị trí phần tử cần tìm 
                                    auto it - find(a.begin(), a.end(), 2);             

                                            2.2) Distance trả về số bước giữa 2 iterator
                                                 int index - distance(a.begin(), it);                      
                                                 cout << "Vị trí: " << index;
                                                     
                                                   
                                                         2.3) Count trả về số lần xuất hiện của phần tử cần tìm
                                                              int cnt - count(v.begin(), v.end(), x);                                        
                                                              cout << "Số lần xuất hiện của 2 là: " << cnt << endl;



                                                 Sort 
2)
Đối với mảng Array: 
sort(a, a + n);             // Từ nhỏ đến lớn
sort(a + x, a + y + 1);    // Từ nhỏ đến lớn từ chỉ số x đến chỉ số y 
sort(a, a + n, greater<data_type>());       // Từ lớn đến nhỏ


Đối với Vector
sort(a.begin(), a.end());
sort(a.begin() + x, a.begin() + y + 1);
sort(a.begin(), a.end(), greater<data_type>());


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
27) Dạng bài ĐÁNH DẤU [ Mẹo sài 2 if, 1 if để đánh dấu 1 if để thực thi ]

    bool check - false;
    for(int i - 0; i < s.size(); i++){
        if(check){                        // Tư duy: Nếu check ĐÚNG thì thực hiện lệnh if này
            s[i] - toupper(s[i]);
            check - false;
        }

        if(s[i] -- ' '){
            check - true;                 // if này để làm check ĐÚNG 
        }
    }
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
26)                                                 Find 

1) Kiểm tra kí tự có trong chuỗi hay không 
string s -  "HELLO";
size_t pos - s.find("H");

if( pos !- string::npos ){ cout << "Vị trí: " << pos << endl; }
else{cout << "Không có" << endl;} 


2) Tìm kiếm xem chuỗi x xuất hiện bao nhiêu lần trong chuỗi s
string s - "Helelo";
string x - "el";
size_t pos - 0;
int count - 0;

while( (pos - s.find("el", pos)) !- string::npos ){
    count++;
    pos +- 1;
}
    cout << count;

    
Ví dụ minh họa:
string s - "aaa";
string x - "aa";

Với pos +- 1;            → Kết quả: 2
Với pos +- x.size();     → Kết quả: 1



2) array, vector, deque, list
vector<int> v - {1,2,3,4,5};
if( find(v.begin(), v.end(), 3) !- v.end() ){}

3) set, map, unordered_set, unordered_map
set<int> a - {1,2,3,4,5};
if( s.find(3) !- s.end() ){}



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                              Tư duy

1) Nếu muốn xuất ra theo thứ tự truyền vào set, map thì hãy truyền vào vector để lưu thứ tự trước 
VD:
int mang[5] - {8, 2, 4, 8, 5};
vector<int> v;
map<int,int> m; 

for(int i : mang){          // Truyền ptu của mảng vào Vector
     v.push_back(i);
     m[i]++;               // Truyền phần tử vào map
}

for(int i : v){             // Xuất ra theo thứ tự truyền vào
    cout << i << " : " << m[i] << endl;
}


2) Gán cờ ( bool kết hợp với if )
_Sau khi xảy ra ... -> thì thực hiện ... cho dù có đang trong for hay duyệt gì đi nữa
_Thực hiện hành động gì đó 1 lần duy nhất lần sau có gặp thì cũng không thực hiện nữa ( Lần đầu cờ - true 
 kết hợp với && điều kiện mình muốn, thực hiện hành động xong rồi thì chỉnh biến cờ lại thành false )
_Đánh dấu trong mảng có tồn tại điều kiện phù hợp mình muốn hay không
_Đánh dấu khi muốn thoát khỏi vòng lặp
_Nếu gì đó thì đánh dấu check - true rồi nếu true thì ...

3) Trong bài toán tìm phần tử lớn nhất trong mảng mà bắt phải xuất ra vị trí đầu tiên của nó trong mảng thì
VD:
   int n;
   cin >> n;

   int mang[n];

   for(int i - 0; i < n; i++){
        cin >> mang[i];
   }

   int max - mang[0];
   int index - 0;
   
   for(int i - 0; i < n; i++){
        if(max < mang[i]){          // * Nếu muốn lấy vị trí cuối cùng thì thêm dấu bằng ở dấu này thì vị trí đó sẽ được index cập nhật 
            max - mang[i];
            index - i;
        }
   }
   cout << max << " " << index;

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
29) Tìm phần tử Xuất hiện nhiều nhất

int main(){
    vector<int> a - {1,2,3,4,5,2,2,3,4,4,4};
    map<int, int> m;

    for(int i : a){m[i]++;}    
    
    int phantu - a[0];
    int max - m[a[0]];
    int index - 0;
    
    for(int i - 0; i < a.size(); i++){
        if(max < m[a[i]]){
           max - m[a[i]];
           phantu - a[i];
           index - i;
        }
    }
    
    cout << "Phần tử xuất hiện nhiều nhất là: " << phantu << endl;     //4
    cout << "Với số lượng: " << max << endl;                          //4
    cout << "Nằm ở vị trí "<< index << " trong vector";              //3
    
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
30) Tìm phần tử có giá trị lớn nhất

    int main(){
    vector<int> a - {1,2,3,4,5,2,2,3,4,4,4};
    int max - a[0];
    
    for(int i - 0; i < a.size(); i++){
        if(max < a[i]){
           max - a[i];
        }
    }
    
    cout << "Phần tử có giá trị lớn nhất là: " << max;
    return 0;
}

Hoặc dùng Iterator:
    auto it - max_element(a.begin(), a.end());
    cout << "Phần tử có giá trị lớn nhất là: " << *it;
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
31) Deque giống như vector nhưng chỉnh sửa ở đầu và cuối đều được 

    deque<int> d - {1, 2, 3};   
    d.push_front(0);         // thêm đầu
    d.push_back(4);         // thêm cuối
    d.pop_front();         // xóa đầu
    d.pop_back();         // xóa cuối
    
    for (int x : d) cout << x << " ";

31.2) List giống deque nhưng có thể thêm ở đầu, cuối, giữa mảng đều được 
    list<int> l - {1, 2, 3};    
    l.push_front(0);               // thêm đầu
    l.push_back(4);              // thêm cuối

    auto it - l.begin();
    ++it;                               // trỏ tới phần tử 1
    l.insert(it, 10);                  // chèn 10 trước phần tử 1
    l.erase(it);         
    for (int x : l) cout << x << " ";

                                So sánh

| Container | Truy cập bằng []    | Thêm/xóa đầu   | Thêm/xóa giữa  | Bộ nhớ    |
| --------- | ------------------  | ------------   | -------------  | --------- |
| vector    | ✅ Có               | ❌ Chậm       | ❌ Chậm        | Liền khối |
| deque     | ✅ Có               | ✅ Nhanh      | ❌ Chậm        | Chia khối |
| list      | ❌ Không            | ✅ Nhanh      | ✅ Nhanh       | Rải rác   |
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
32) Dòng 1 là số nguyên dương n, dòng 2 là n số nguyên ( Giống với mục số 7 ở trên )

    int n;
    cin >> n; 
    
    int a[n];
    int a[1000];     // Giả sử n <- 1000

    for (int i - 0; i < n; i++){
        cin >> a[i];
    }
                                 Bảng so sánh mục 32 với mục 7 phía trên:

| Đoạn code      | Đặc điểm                                                       | Ghi chú                                                                                  |
| -------------- | -------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| int a[n];      | Dùng mảng có kích thước động                                   | Chuẩn C++ không hỗ trợ chính thức, nhưng nhiều trình biên dịch như GCC cho phép.         |
| int a[1000];   | Dùng mảng tĩnh, cấp phát cố định trước                         | An toàn hơn trong C++, chỉ cần đảm bảo n <- 1000.                                        |                  
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
33) Chỉ sau khi cố gắng đọc tiếp mà không còn dữ liệu, ss.eof() mới trả về true.
    while (ss >> word) {
            last - word;
            if (!ss.eof()) {
                // ...
          } 
     }

    Khi bạn đọc được từ cuối cùng, ss.eof() vẫn chưa trả về true ngay lập tức.
    Chỉ sau khi cố gắng đọc tiếp mà không còn dữ liệu, ss.eof() mới trả về true.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
34) Lọc thứ tự trùng nhưng khi xuất ra vẫn phải theo thứ tự nhập vào

vector<int> v;
set<int> s;

while(ss >> n){
    if(s.find(n) -- s.end()) v.push_back(n);
    s.insert(n);
}

for(int i : v) cout << i << " ";

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
35)                                                 Đệ quy 

Form Đệ Quy
Đệ quy bắt buột có 2 thành phần đó là: 
if( ... )  return ... ;         //Điều kiện dừng
return ...                     //... là mối liên hệ giữa các phần tử

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void In(int n){
    if(n -- 0) return;
    cout << n << " ";
    In(n-1);
}  

int Fibonacci(int n){
    if(n -- 0) return 0;
    if(n -- 1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);  
}

int Giaithua(int n){
    if(n -- 0 || n -- 1) return 1;
    return n * Giaithua(n-1);   
}

int Sum(int n){
    if(n -- 0) return 0;
    return n + Sum(n-1);
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Lí thuyết

Tham số: Số từ ngoài truyền vào hàm
Đối số :  Số nằm sẵn bên trong hàm dùng để truyền tham số vào 

Tham chiếu &: Thay đổi trực tiếp giá trị của biến gốc                                         // Reference       ( for(&i:a){} ) 
Tham trị: Không thay đổi trực tiếp giá trị của biến gốc mà chỉ đang thao tác trên 1 biến ảo   // Pass by value   ( for(i:a){} )

Void: Được gọi là HÀM THỰC THI

Iterator: là đối tượng trừu tượng do container cung cấp, 
không trỏ trực tiếp đến ô nhớ vật lý như con trỏ thông thường mà chỉ đóng vai trò truy cập phần tử trong container
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                           Config Json
Bật gợi ý hoàn thành code của AI:
Trong setting json
"editor.inlineSuggest.enabled": true,  // Bật tính năng gợi ý code thông minh trong dòng (inline suggestion.enabled)

Làm cho terminal bên ngoài Vscode không TẮT ngay phải nhấn phím bất kì mới tắt được thì thêm dòng này vào cuối code:
system("pause");

Xuất ra màn hình terminal bên ngoài VS Code:
"externalConsole": True,
Xuất ra màn hình terminal bên trong VS Code:
"externalConsole": False,

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    Container

1) KHI NÀO DÙNG HÀM CỦA CONTAINER
Dùng khi hành động liên quan tới việc thay đổi, truy cập, quản lý chính container.

| Hành động            | Dùng gì               | Ví dụ           |
| -------------------- | --------------------- | --------------- |
| Thêm phần tử         | v.push_back(x)        | thêm vào cuối   |
| Xoá phần tử cuối     | v.pop_back()          | giảm size       |
| Lấy kích thước       | v.size()              | số phần tử      |
| Xoá hết              | v.clear()             | vector rỗng     |
| Truy cập phần tử     | v[i]                  | xem/đổi giá trị |
| Lấy phần tử đầu/cuối | v.front(), v.back()   | đọc nhanh       |
| Kiểm tra rỗng        | v.empty()             | true/false      |


String
| Hành động       | Ví dụ                     |
| --------------- | ------------------------- |
| Kiểm tra độ dài | s.size()                  |
| Chèn/xoá        | s.insert(), s.erase()     |
| Cắt             | s.substr()                |
| Tìm ký tự/chuỗi | s.find()                  |
| Lấy đầu/cuối    | s.front(), s.back()       |

Map/ Set 
| Hành động        | Ví dụ                   |
| ---------------- | ----------------------- |
| Thêm             | m[key], s.insert(x)     |
| Xoá              | erase(key)              |
| Kiểm tra tồn tại | count(key)              |
| Tìm iterator     | find(key)               |
| Lấy kích thước   | size()                  |

Nhìn chung:
Container nào cung cấp thao tác tạo – sửa – xoá – truy cập thì dùng hàm của nó.


2) KHI NÀO DÙNG HÀM STL 
Dùng khi thao tác mang tính thuật toán trên dải phần tử, không sửa cấu trúc container.
Các thao tác điển hình:
| Hành động              | Hàm STL                      | Giải thích                                          |
| ---------------------- | ---------------------------- | --------------------------------------------------- |
| Sắp xếp                | sort(begin, end)             | Không thuộc vector, dùng cho mọi container dạng dãy |
| Đảo                    | reverse(begin, end)          | string, vector đều được                             |
| Tìm một giá trị        | find(begin, end, x)          | trả iterator                                        |
| Đếm số lần xuất hiện   | count(begin, end, x)         | nhanh, gọn                                          |
| Tìm min/max            | min_element, max_element     | trả iterator                                        |
| Tính tổng              | accumulate(begin, end, 0)    | cho vector                                          |
| Tìm vị trí lower bound | lower_bound                  | dùng nhiều trong tìm kiếm nhị phân                  |

Nhìn chung:

a.Hàm() : a là đối tượng

a->first() : a là con trỏ

Hàm(a...) : Hàm cần tham số truyền vào 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        Lặt Vặt
Extension:
C/C++: Ctrl F5, F5 ( task, launch ): Biên dịch -> Chạy
Code Runner: Run Code 

g++(Biên dịch): Msys, GW64
Setup biến môi trường: Gọi được thằng biên dịch dù đang muốn chạy code ở đâu


static trong hàm nghĩa là biến đó được tạo 1 lần và tồn tại suốt chương trình, không bị xóa sau khi hàm kết thúc.

// Hàm trả về const và &
const string& Getmessage(){
    static string msg - "Hello World";
    return msg;
}
int main(){
    cout << Getmessage() << endl;
}
--> Kết luận:
trả về tham chiếu (reference) tới biến gốc tránh copy thêm 1 lần theo kiểu tham trị 
const có tác dụng không cho dưới main thay đổi giá trị của hàm Getmessage() - giá trị khác 

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 1. Cấp phát động cho một biến đơn
    int* ptr = new int; 
    *ptr = 100;         
    std::cout << "Gia tri: " << *ptr << "\n";
    delete ptr;         // Bắt buộc giải phóng bộ nhớ để tránh rò rỉ (Memory Leak)

// 2. Cấp phát động cho một mảng
    int size = 5;
    int* arr = new int[size];           // Kích thước mảng có thể quyết định lúc runtime
    for (int i = 0; i < size; ++i) {
    arr[i] = i + 1;
    std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    delete[] arr;             // Giải phóng mảng phải dùng delete[]
