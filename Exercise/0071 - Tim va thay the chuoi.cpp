#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,x,y;
    getline(cin, s);
    getline(cin, x);
    getline(cin, y);

    size_t pos = 0;
    while( (pos = s.find(x,pos)) != string::npos ){
        s.erase(pos, x.size());
        s.insert(pos, y);
        pos += y.size();
    }
    cout << s;
}   