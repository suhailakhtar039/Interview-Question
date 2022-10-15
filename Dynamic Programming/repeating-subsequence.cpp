// Author : Suhail Akhtar
// Date : 15-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int n = s.length();
    int lcs[n+1][n+1]={0};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s[i-1]==s[j-1] && i!=j)
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[n][n]>=2?1:0;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}