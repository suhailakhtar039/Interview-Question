// Author: Suhail Akhtar
// Date  : 26-08-22
#include<bits/stdc++.h>
using namespace std;
int mxL,mxR,mxLen;
void palindrome(string &A,int i,int j,int &n){
    while(i>=0 && j<n && A[i]==A[j])i--,j++;
    int len=j-i-1;
    if(len>mxLen){
        mxLen=len;
        mxL=++i;
        mxR=--j;
    }
}
string solve(string A){
    int n=A.length();
    if(n<=1)return A;
    mxL=-1;
    mxR=-1;
    mxLen=0;
    for(int i=0; i<n-1; i++){
        palindrome(A,i,i,n);
        palindrome(A,i,i+1,n);
    }
    string ans="";
    for(int i=mxL; i<=mxR; i++)
        ans+=A[i];
    return ans;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}