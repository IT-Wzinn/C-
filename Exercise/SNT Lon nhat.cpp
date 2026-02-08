#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std; 

bool Isprime(int n){
    if(n<=1){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    vector<int> a;
    vector<int> b;
    
    string line;
    getline(cin, line);

    // Biến dòng line thành biến tên ss
    stringstream ss(line);
    int n;

    // Truyền từng giá trị của biến ss vào n
    while (ss >> n){
       if(Isprime(n)){
        a.push_back(n);
    }
  }

    // Sắp vector a tăng dần để tìm ra SNT lớn nhất
    sort(a.begin(), a.end());
    cout << a.back();          
}
/*
v.front : Phần tử đầu mảng
v.back : Phần tử cuối mảng
*/