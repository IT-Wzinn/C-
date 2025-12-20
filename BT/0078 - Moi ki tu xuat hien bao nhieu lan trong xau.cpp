#include <bits/stdc++.h>

 

using namespace std;
int main(){
    string s;
    getline(cin, s);

    vector<char> v;
    map<char,int> m;

    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);

        if(m.find(s[i]) == m.end()){
            v.push_back(s[i]);
        }
        m[s[i]]++;
    }

    for(char c : v){
        cout << c << ":" << m[c] << " ";
    }
 
}   