// Author: Suhail Akhtar
// Date  : 24-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(string A, string B){
    if(B=="" || A=="")return -1;
    int n=A.length(), m=B.length();
    if(m>n)return -1;
    for(int i=0; i<=n-m; i++){
        string temp = A.substr(i,m);
        if(temp==B)return i;
    }
    return -1;
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}