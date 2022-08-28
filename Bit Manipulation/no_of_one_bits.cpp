// Author : Suhail Akhtar
// Date : 28-08-22
#include <bits/stdc++.h>
using namespace std;
int solve(int A){
    int cnt = 0;
    while(A){
        if(A&1)cnt++;
        A>>=1;
    }
    return cnt;
}
int main(){
    int a;cin>>a;
    cout<<solve(a);
}