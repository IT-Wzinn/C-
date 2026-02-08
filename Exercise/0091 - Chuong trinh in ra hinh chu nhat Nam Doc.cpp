#include <iostream>
using namespace std;

void VeHCN(int d, int r){
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= r; j++){
            if(i == 1 || i == d || j == 1 || j == r){
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

7 5
*****
*   *
*   *
*   *
*   *
*   *
*****

*/