#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>     
using namespace std;

//Kiểm tra số Nguyên tố
bool Isprime(int n){
    if(n<=1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){         
    vector<int> a;
    int n; 

    //Nhập từng số vào vector nếu nhấn enter hoặc chữ thì dừng
    cout << "Nhập số vào vector: ";
    while(cin >> n){
        a.push_back(n);
        if(cin.get() == '\n'){
            break;
        }
    }

    //Kiểm tra từng số trong mảng xem phải số Isprime không
    int sum = 0, count = 0;
    for(int i = 0; i < a.size(); i++){
        if(Isprime(a[i])){
            sum += a[i];
            count++;
        }
    }
    
    if(count>0) cout << "Trung bình số nguyên tố: " << fixed << setprecision(2) << double(sum)/count;
   
    else cout << "-";
}