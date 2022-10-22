// Author : Suhail Akhtar
// Date : 22-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A)
{
    int ans = INT_MIN;
    int prod = 1;
    for (int i = 0; i < A.size(); i++)
    {
        prod *= A[i];
        ans = max(ans, prod);
        if (prod == 0)
            prod = 1;
    }
    prod = 1;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        prod *= A[i];
        ans = max(ans, prod);
        if (prod == 0)
            prod = 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << solve(v);
}