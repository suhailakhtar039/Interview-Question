// Author : Suhail Akhtar
// Date : 31-08-22
#include<bits/stdc++.h>
using namespace std;
char reverseChar(char c){
    if(c=='(') return ')';
    if(c=='[') return ']';
    return '}';
}
int solve(string A){
    stack<char> s;
    for(char c:A){
        if(c=='(' || c=='[' || c=='{'){
            s.push(c);
        }else{
            if(s.empty())return 0;
            char t=reverseChar(s.top());s.pop();
            if(c!=t)return 0;
        }
    }
    return s.empty();
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}