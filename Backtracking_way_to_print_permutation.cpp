#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}
template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}

void solve1(vector<int> &curr, vector<int> &a, vector<bool> &vis, int &count)
{
    if (curr.size() == a.size())
    {
        cout << curr << endl;
        count++;
        return;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            curr.push_back(a[i]);
            solve1(curr, a, vis, count);
            vis[i] = false;
            curr.pop_back();
        }
    }
}
int solve(vector<int> &a)
{
    int n = a.size();
    vector<bool> vis(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        vis[i] = true;
        vector<int> curr;
        curr.push_back(a[i]);
        solve1(curr, a, vis, count);
        curr.pop_back();
        vis[i] = false;
    }
    return count;
}
int32_t main()
{
    fio;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cout << solve(a);
    return 0;
}
