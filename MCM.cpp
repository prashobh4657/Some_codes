#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 0;
            else if (g == 1)
                dp[i][j] = a[i] * a[j] * a[j + 1];
            else
            {
                int result = INT_MAX;
                for (int k = i; k < j; k++)
                    result = min(result, dp[i][k] + dp[k + 1][j] + (a[i] * a[k + 1] * a[j + 1]));
                dp[i][j] = result;
            }
        }
    }
    cout << dp[0][n - 2];

    return 0;
}