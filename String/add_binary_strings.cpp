// Author : Suhail Akhtar
// Date : 29-08-22
#include <bits/stdc++.h>
using namespace std;
string solve(string A,string B){
    string ans="";
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int i=0,j=0,n=A.length(),m=B.length();
    int carry=0;
    while (i<n && j<m){
        int no1 = A[i]-'0';
        int no2 = B[j]-'0';
        int sum=no1+no2+carry;

        int noToPut = sum%2;
        carry = sum/2;
        ans+=noToPut+'0';
        i++;j++;
    }
    while (i<n){
        int no1 = A[i]-'0';
        int sum=no1+carry;
        int noToPut = sum%2;
        carry = sum/2;
        ans+=noToPut+'0';
        i++;
    }
    while(j<m){
        int no2 = B[j]-'0';
        int sum=no2+carry;
        int noToPut = sum%2;
        carry = sum/2;
        ans+=noToPut+'0';
        j++;
    }
    if(carry)ans+='1';
    reverse(ans.begin(),ans.end());
    return ans; 
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}