// Author : Suhail Akhtar
// Date : 12-09-22
#include<bits/stdc++.h>
using namespace std;
int operation(int a,int b,string op){
    if(op=="+")
        return a+b;
    else if(op=="-")
        return a-b;
    else if(op=="*")
        return a*b;
    else
        return a/b;
}
int solve(vector<string> &v){
    stack<int> s;
    for(int i=0; i<v.size(); i++){
        if(v[i]=="*" or v[i]=="+" or v[i]=="-" or v[i]=="/"){
            int op2 = s.top();s.pop();
            int op1 = s.top();s.pop();
            int result = operation(op1,op2,v[i]);
            // cout<<"op1 = "<<op1<<" op2= "<<op2<<" result = "<<result<<endl;
            s.push(result);
        }
        else{
            s.push(stoi(v[i]));
        }
    }
    return s.top();
}
int main(){
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v)<<endl;
}