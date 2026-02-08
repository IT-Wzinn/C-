#include <iostream>
using namespace std;

void VeHCN(int d, int r){
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= d; j++){
            if(i == 1 || i == r || j == 1 || j == d){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int d,r;
    cin >> d >> r;
    VeHCN(d,r);
}

/* 

15 4
***************
*             *
*             *
***************

*/