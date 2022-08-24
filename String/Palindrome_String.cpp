// Author: Suhail Akhtar
// Date  : 24-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(string A){
    string plan="";
    for(auto &c:A){
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')){
            if((c>='a' && c<='z')||(c>='A' && c<='Z'))
                plan+=tolower(c);
            else
                plan+=c;
        }
    }
    // cout<<"plan = "<<plan<<endl;
    int i=0,j=plan.length()-1;
    while(i<=j){
        if(plan[i]!=plan[j])
            return 0;
        i++,j--;
    }
    return 1;
}
int main(){
    string a;cin>>a;
    cout<<solve(a)<<endl;
}