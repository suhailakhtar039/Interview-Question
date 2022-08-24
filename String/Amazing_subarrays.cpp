// Author: Suhail Akhtar
// Date  : 25-08-22
#include<bits/stdc++.h>
using namespace std;
bool isVowel(char &c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
        return true;
    return false;
}
int solve(string A){
    bool firstVowel = false;
    int mod=1e4+3;
    int ans=0,noOfVowel=0;
    for(auto &c:A){
        if(isVowel(c))firstVowel=true;
        if(firstVowel){
            if(isVowel(c))noOfVowel++;
            ans=(ans+noOfVowel)%mod;
        }
    }
    return ans;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}