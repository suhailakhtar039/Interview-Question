// Author : Suhail Akhtar
// Date : 16-10-22
#include<bits/stdc++.h>
using namespace std;
int mem[701][701];
int distinct(string a,string b,int n,int m){
    if(m<0)return 1;
    if(n<0)return 0;
    if(mem[n][m]!=-1)return mem[n][m];
    if(a[n]==b[m]){
        return mem[n][m] = distinct(a,b,n-1,m-1)+distinct(a,b,n-1,m);
    }else
    return mem[n][m] = distinct(a,b,n-1,m);
}
int solve(string a,string b){
    int n = a.length(),m = b.length();
    for(int i=0; i<=700; i++)
    for(int j=0; j<=700; j++)mem[i][j]=-1;
    return distinct(a,b,n-1,m-1);
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}