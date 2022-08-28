// Author : Suhail Akhtar
// Date : 28-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(int a){
    int cnt=0;
    while(a){
        if((a&1) == 0)cnt++;
        else break;
        a>>=1;
    }
    return cnt;
}
int main(){
    int a;cin>>a;
    cout<<solve(a);
}