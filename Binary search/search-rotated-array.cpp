// Author: Suhail Akhtar
// Date  : 22-08-22
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; i++)cin>>A[i];
    int B;cin>>B;

    int first = 0, last = n-1, mid;
    while(first<=last){
        mid=(first+last)>>1;
        if(A[mid]==B){
            cout<<mid<<endl;
            return 0;
        }
        // left array sorted
        if(A[mid]>A[first]){
            if(B>=A[first] && B<=A[mid])
                last=mid-1;
            else
                first=mid+1;
        }
        else{
            if(B>=A[mid] && B<=A[last])
                first=mid+1;
            else
                last=mid-1;
        }
    }
    cout<<-1<<endl;

}