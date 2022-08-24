// Author: Suhail Akhtar
// Date  : 24-08-22
#include<bits/stdc++.h>
using namespace std;
bool isVowel(char &c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}
int solve(string A){
    int n=A.length();
    int vowels[n]={0};
    int constants[n]={0};
    vowels[0]=isVowel(A[0])?1:0;
    constants[0]=!isVowel(A[0])?1:0;
    for(int i=1; i<n; i++){
        if(isVowel(A[i]))
            vowels[i]=vowels[i-1]+1;
        else
            vowels[i]=vowels[i-1];

        if(!isVowel(A[i]))
            constants[i]=constants[i-1]+1;
        else
            constants[i]=constants[i-1];
    }
    int ans=0,mod=1e9+7;
    for(int i=0; i<n; i++){
        if(isVowel(A[i])){
            ans=(ans%mod+constants[i])%mod;
        }else{
            ans=(ans%mod+vowels[i])%mod;
        }
    }
    return ans;
}
int main(){
    string a;cin>>a;
    cout<<solve(a);
}