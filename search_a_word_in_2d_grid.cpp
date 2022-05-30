#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
 Question :  https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/
 8 Directions  : Up , down , right, left, 4 diagonals;
 Till now diagonal matching is not implmented
 that will be same as in case of n-queen.
 or i will implement it later
  ==> in this question recursion is not involved;
  ==> also see article solution, how they implemented using very short code unlike as that of mine;
*/
bool up(string s, vector<vector<char>> v, int r, int c)
{
    int i = 0;
    while (i < s.size() && r >= 0)
    {
        if (v[r][c] == s[i])
        {
            r--;
            i++;
        }
        else
            return false;
    }
    if (i == s.size()) // full string verified;
        return true;

    return false; // while loop terminated because of condition r>=0;
}

bool down(string s, vector<vector<char>> v, int r, int c)
{
    int i = 0;
    while (i < s.size() && r < v.size())
    {
        if (v[r][c] == s[i])
        {
            r++;
            i++;
        }
        else
            return false;
    }
    if (i == s.size()) // full string verified;
        return true;

    return false; // while loop terminated because of condition r<v.size()
}

bool left(string s, vector<vector<char>> v, int r, int c)
{
    int i = 0;
    while (i < s.size() && c >= 0)
    {
        if (v[r][c] == s[i])
        {
            c--;
            i++;
        }
        else
            return false;
    }
    if (i == s.size()) // full string verified;
        return true;

    return false; // while loop terminated because of condition c>=0;
}

bool right(string s, vector<vector<char>> v, int r, int c)
{
    int i = 0;
    while (i < s.size() && c < v[0].size())
    {
        if (v[r][c] == s[i])
        {
            c++;
            i++;
        }
        else
            return false;
    }
    if (i == s.size()) // full string verified;
        return true;

    return false; // while loop terminated because of condition c<v[0].size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    string s;
    cin >> s;
    vector<pair<char, pair<int, int>>> ans;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == s[0])
            {
                if (up(s, v, i, j))
                {
                    ans.push_back({'U', {i, j}});
                    count++;
                }
                else if (down(s, v, i, j))
                {
                    ans.push_back({'D', {i, j}});
                    count++;
                }
                else if (left(s, v, i, j))
                {
                    ans.push_back({'L', {i, j}});
                    count++;
                }
                else if (right(s, v, i, j))
                {
                    ans.push_back({'R', {i, j}});
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;

    return 0;
}
