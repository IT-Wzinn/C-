#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
// Đảo ngược kí tự bên trong phần tử  
    string line;
    getline(cin, line);

    stringstream ss(line);
    string s;

    vector<string> v;
    while(ss >> s){
       reverse(s.begin(), s.end());
       v.push_back(s);
    }
    for(string s : v){
        cout << s << " ";
    }
}

// Đảo ngược chuỗi
    string line;
    getline(cin, line);

    stringstream ss(line);
    string s;

    vector<string> v;
    while(ss >> s){
        v.push_back(s);
    }
    reverse(v.begin(), v.end());
    for(string s : v){
        cout << s << " ";
    }