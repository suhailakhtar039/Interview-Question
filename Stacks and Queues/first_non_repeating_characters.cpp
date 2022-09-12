// Author : Suhail Akhtar
// Date : 12-09-22
#include<bits/stdc++.h>
using namespace std;
string solve(string s){
    int n=s.length();
    string ans="";
    queue<char> q;
    unordered_map<char,int> m;
    for(const auto &it:s){
        cout<<"it= "<<it<<endl;
        m[it]++;
        q.push(it);
        while(q.size() && m[q.front()]!=1){
            q.pop();
        }
        if(q.size())
            ans+=q.front();
        else
            ans+="#";
        // cout<<"ans= "<<ans<<endl;
    }
    return ans;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}