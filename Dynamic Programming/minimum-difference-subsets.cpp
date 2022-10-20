// Author : Suhail Akhtar
// Date : 20-10-22
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> A)
{
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }

    int MIN[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                MIN[i][j] = 0;
            }
            if (j == 0)
            {
                MIN[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (A[i - 1] <= j)
            {
                MIN[i][j] = MIN[i - 1][j] || MIN[i - 1][j - A[i - 1]];
            }
            else
            {
                MIN[i][j] = MIN[i - 1][j];
            }
        }
    }
    vector<int> v;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (MIN[n][i] == 1)
        {
            v.push_back(i);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        ans = min(sum - 2 * v[i], ans);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v);
}