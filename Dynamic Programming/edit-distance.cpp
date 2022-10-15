// Author : Suhail Akhtar
// Date : 15-10-22
#include<bits/stdc++.h>
using namespace std;
int solve(string a,string b){
    int n = a.length(), m = b.length();
    int editDistance[n+1][m+1]={0};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0)
                editDistance[i][j]=j;
            else if(j==0)
                editDistance[i][j]=i;
            else if(a[i-1]==b[j-1])
                editDistance[i][j]=editDistance[i-1][j-1];
            else
                editDistance[i][j]=1+min(editDistance[i-1][j-1],min(editDistance[i-1][j],editDistance[i][j-1]));
        }
    }
    return editDistance[n][m];
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}