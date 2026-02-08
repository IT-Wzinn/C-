#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<int> mang(n);
    map<int,int> m;

    for(int i = 0; i < n; i++){
        cin >> mang[i];
        m[mang[i]]++;
    }

    int a = mang[0];
    int max = m[a];

    for(int i = 0; i < n; i++){
        if(max < m[mang[i]]){
           max = m[mang[i]];
           a = mang[i];
        }
    }
    cout << a << " " << max;
}


/*
Input #1 
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
2 4
*/