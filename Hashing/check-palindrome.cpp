// Author : Suhail Akhtar
// Date : 28-09-22
#include<bits/stdc++.h>
using namespace std;

int solve(string s){
    int n=s.length();
    unordered_map<char,int> m;
    for(int i=0; i<n; i++){
        m[s[i]]++;
    }
    int odd=0;
    for(auto it:m){
        if(it.second%2&1)odd++;
    }
    if(odd>1)return 0;
    return 1;
}

int main()
{
    string s;cin>>s;
    cout<<solve(s);
    return 0;
}
