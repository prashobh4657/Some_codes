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
int32_t main()
{
    fio;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            swap(v[i][j], v[j][i]);
    }
    for (int i = 0; i < n; i++)
        reverse(v[i].begin(), v[i].end());
    for (int i = 0; i < n; i++)
        cout << v[i] << endl;
    cout << endl;

    return 0;
}
//Transpose the matrix and then reverse each row; (Transpose also without extra space);
