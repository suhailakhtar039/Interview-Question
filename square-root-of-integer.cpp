// Author: Suhail Akhtar
// Date  : 22-08-22
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    if(n==1){
        cout<<n<<endl;
    }
    long long first = 1, last = n/2, mid, ans;
    while (first<=last){
        mid = first +(last-first)/2;
        if(mid*mid==n){
            cout<<mid;
            return 0;
        }else if(mid*mid>n)
            last = mid-1;
        else{
            first = mid+1;
            ans = mid;
        }
    }
    cout<<ans<<endl;
    
}