// Author : Suhail Akhtar
// Date : 30-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int cnt=0;
    for(auto it:s){
        if(it=='(')cnt++;
        else cnt--;

        if(cnt<0)return 0;
    }
    return cnt==0;
}
int main(){
    string s;cin>>s;
    cout<<solve(s);
}