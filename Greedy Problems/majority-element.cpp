// Author : Suhail Akhtar
// Date : 25-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v){
    int n = v.size();
    int cnt = 1, maj = v[0];
    for(int i=1; i<n; i++){
        if(maj == v[i])cnt++;
        else{
            cnt--;
            if(cnt == 0){
                maj = v[i];
                cnt = 1;
            }
        }
    }
    return maj;
}
int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    cout<<solve(v);
}