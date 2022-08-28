// Author : Suhail Akhtar
// Date : 28-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    stringstream ss(s);
    string temp;
    while(ss>>temp){}
    // cout<<temp<<endl;
    return temp.length();
}
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;
    cout<<solve(s)<<endl;
}