// Author : Suhail Akhtar
// Date : 16-10-22
#include<bits/stdc++.h>
using namespace std;
// top down approach
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
    int dis[n+1][m+1]={0};
    for(int i=0; i<=n; i++)dis[i][0]=1;
    for(int j=0; j<=m; j++)dis[0][j]=0;
    dis[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1])
                dis[i][j]=dis[i-1][j]+dis[i-1][j-1];
            else
                dis[i][j]=dis[i-1][j];
        }
    }
    return dis[n][m];
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}