#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Question : https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/ 
// Backtracking Solution 

void solve(int i, int j, vector<vector<int>> matrix, string curr, vector<string> &ans)
{
    if (i == matrix.size() - 1 && j == matrix[0].size() - 1) // Reach condition;
    {
        curr.push_back(' ');
        curr.push_back(matrix[i][j] + '0');
        ans.push_back(curr);
        return;
    }

    if (curr.size() != 0) // formatting the output
        curr.push_back(' ');

    curr.push_back(matrix[i][j] + '0');

    if (j + 1 <= matrix[0].size() - 1) // Go there only if it exists;
        solve(i, j + 1, matrix, curr, ans);

    if (i + 1 <= matrix.size() - 1) // Go there only if it exists;
        solve(i + 1, j, matrix, curr, ans);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    vector<string> ans;
    string curr;
    solve(0, 0, matrix, curr, ans);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
/*
Input : 
3 3
1 2 3
4 5 6
7 8 9

Output : 
1 2 3 6 9
1 2 5 6 9
1 2 5 8 9
1 4 5 6 9
1 4 5 8 9
1 4 7 8 9

*/
