#include <iostream>
using namespace std;
int main(){
    string s = "Hello World";
    size_t pos = s.find("W");
    
    if(pos != string::npos){ cout << "Vị trí: " << pos << endl; }
    else{cout << "Không có" << endl;}   

//Tìm kiếm x trong chuỗi 
    string line,x;
    getline(cin,line);
    getline(cin,x);

    int count = 0;
    size_t pos = 0;

// Tìm 1 lần 
    if((pos = line.find(x)) != string::npos){ cout << "Có"; }
    else{cout << "Không";}


// Tìm nhiều lần
    while( (pos = line.find(x,pos)) != string::npos ){
         count++;
         pos++;
    }

    cout << count;
}

LƯU Ý: 
pos += 1;        → Đếm cả các trường hợp lặp/chồng lên nhau.
pos += x.size(); → Không đếm các trường hợp lặp/chồng lên nhau.

Ví dụ minh họa:
string s = "aaa";
string x = "aa";

Với pos += 1;            → Kết quả: 2
Với pos += x.length();   → Kết quả: 1

===================================================================================================================================================

***Kiểm tra xem x có trong string hay container hay không

                                   FIND
1) Kiểm tra xem phần tử có trong chuỗi hay không  (1 lần)
string s =  "HELLO";
size_t pos = s.find("H");
if( pos != string::npos ){}

2) Kiểm tra xem phần tử có trong chuỗi bao nhiêu lần (Nhiều lần)
size_t pos = 0; 
while( (pos = s.find(x, pos)) != string::npos){
count++;
pos++;}

3) array, vector, deque, list    (Container)
   vector<int> v = {1,2,3,4,5};
   if(find(v.begin(), v.end(), 3) != v.end()){}

4) set, map, unordered_set, unordered_map   (Set, map,...)
   set<int> a = {1,2,3,4,5};
   if(a.find(3) != a.end()){}
   
======================================================================================================================================================================================================================================================================================================
if(pos = line.find(x) != string::npos){} : Tìm kiếm 1 lần xem có tồn tại hay không. 
while((pos = line.find(x,pos)) != string::npos){count++; & pos += 1;} : Tìm kiếm nhiều lần.
======================================================================================================================================================================================================================================================================================================
