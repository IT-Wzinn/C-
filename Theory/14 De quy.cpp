#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);  
}

int Giaithua(int n){
    if(n == 0 || n == 1) return 1;
    return n * Giaithua(n-1);   
}

int Sum(int n){
    if(n == 0) return 0;
    return n + Sum(n-1);
}

void In(int n){
    if(n == 0) return;
    cout << "Hello World" << endl;
    In(n-1);
}

int main(){
    
}