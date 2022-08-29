// Author : Suhail Akhtar
// Date : 29-08-22
#include<bits/stdc++.h>
using namespace std;
int solve(string v1,string v2){
    int n=v1.length(),m=v2.length();
    int i=0,j=0;
    for(;i<n || j<m;){
        int vnum1=0,vnum2=0;
        while (i<n && v1[i]!='.'){
            vnum1=vnum1*10+v1[i]-'0';
            i++;
        }

        while(j<m && v2[j]!='.'){
            vnum2=vnum2*10+v2[j]-'0';
            j++;
        }

        if(vnum1>vnum2)return 1;
        else if(vnum1<vnum2)return 0;
        i++;j++;
    }
    return -1;
}
int main(){
    string a,b;cin>>a>>b;
    cout<<solve(a,b);
}