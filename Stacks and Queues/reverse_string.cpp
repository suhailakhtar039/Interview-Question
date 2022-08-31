// Author : Suhail Akhtar
// Date : 31-08-22
#include<bits/stdc++.h>
using namespace std;
string solve(string A){
    stack<char> s;
    for(const auto &c:A)
        s.push(c);
    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}