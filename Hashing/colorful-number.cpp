// Author : Suhail Akhtar
// Date : 20-09-22
#include<bits/stdc++.h>
using namespace std;
int colorful(int A) {
    vector<int> digits;
    unordered_set<int> st;
    while(A!=0){
        digits.push_back(A%10);
        A/=10;
    }
   
    int N = digits.size();
    reverse(digits.begin(), digits.end());
   
    int x = 0;
    vector<int> v(N, 1);
   
    while(x <= N-1){
        int j = 0;
        for(int i = x; i < N; i++){
            v[j] = v[j]*digits[i];
            auto itr = st.find(v[j]);
            if(itr != st.end())
                return 0;
            st.insert(v[j]);
            j++;
        }
        x++;
    }
   
    return 1;
}
