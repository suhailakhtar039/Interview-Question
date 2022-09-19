// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
string letters[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void helper(vector<string> &ans,string s,string temp="",int idx=0){
    int n = s.length();
    if(idx == n){
        ans.push_back(temp);
        return;
    }
    int curIdx = s[idx]-'0';
    for(int i=0; i<letters[curIdx].length(); i++){
        temp+=letters[curIdx][i];
        helper(ans,s,temp,idx+1);
        temp.pop_back();
    }
}
vector<string> solve(string &s){
    vector<string> ans;
    helper(ans,s);
    return ans;
}
int main(){
    string s;cin>>s;
    vector<string> ans = solve(s);
    for(auto it:ans){
        cout<<it<<" ";
    }
}