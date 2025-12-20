#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,x;
    getline(cin, s);
    getline(cin, x);

    size_t pos = 0;
    int count = 0;
    while( (pos = s.find(x, pos)) != string::npos ){
        count++;
        pos += x.size();
    }
    cout << count;
}   