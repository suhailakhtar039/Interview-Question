// Author : Suhail Akhtar
// Date : 29-09-22
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int n = s.length();
    unordered_map<char,int> m;
    int j=0,ans=0;
    for(int i=0; i<n; i++){
        if(m.count(s[i])){
            j=max(j,m[s[i]]+1);
        }
        ans=max(ans,i-j+1);
        m[s[i]]=i;
    }
    return ans;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}