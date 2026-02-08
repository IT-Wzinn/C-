#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    int  mang[1000];
    bool check[1000] = {false};

    for(int i = 0; i < n; i++){
        cin >> mang[i];
    }

    for(int i = 0; i < n; i++){
        if(check[i] == true) continue;
        int dem = 1;
        for(int j = i + 1; j < n; j++){
            if(mang[i] == mang[j]){
                dem++;
                check[j] = true;
            }
        }
            cout << mang[i] << " " << dem << endl;
    }
}
/*Input #1 
14
4
-4
-1
-4
2
2
2
5
1
-2
-4
2
-5
1

Output #1 
4 1
-4 3
-1 1
2 4
5 1
1 2
-2 1
-5 1
*/