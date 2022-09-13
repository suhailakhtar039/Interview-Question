// Author : Suhail Akhtar
// Date : 14-09-22
#include<bits/stdc++.h>
using namespace std;
void helper(string &ans,string s,int k){
    if(k==0)return;
    int n=ans.length();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
                if(s>ans)ans=s;
                helper(ans,s,k-1);
                swap(s[j],s[i]);
            }
        }
    }
}
string solve(string s,int k){
    string ans=s;
    helper(ans,s,k);
    return ans;
}
int main(){
    string s;cin>>s;
    int k;cin>>k;
    cout<<solve(s,k);
}