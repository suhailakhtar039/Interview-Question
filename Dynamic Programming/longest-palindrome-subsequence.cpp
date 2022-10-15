// Author : Suhail Akhtar
// Date : 15-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(string a){
    string b = a;
    reverse(b.begin(),b.end());
    int n=a.length(),m = b.length();
    int lcs[n+1][m+1]={0};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(a[i-1]==b[j-1])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[n][m];
}
int main(){
    string a;cin>>a;
    cout<<solve(a)<<endl;
}