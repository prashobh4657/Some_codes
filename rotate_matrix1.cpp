#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void rotate(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> temp;
    for (int i = 0; i < m; i++)
    {
        vector<int> z;
        for (int j = 0; j < n; j++)
            z.push_back(v[j][i]);

        temp.push_back(z);
    }
    for (int i = 0; i < temp.size(); i++)
        reverse(temp[i].begin(), temp[i].end());
    v = temp;
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    rotate(v);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
/*
Question : https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/ 
--> Above solution is using extra space.
*/
