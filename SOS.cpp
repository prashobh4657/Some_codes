#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(int idx, vector<int> a, int sum, int curr, string t)
{
    if (idx == a.size())
    {
        if (curr == sum)
            cout << t << endl;
        return;
    }
    
    if(curr==sum)  //discard the exploration of further nodes , if curr==sum means answer till now is t, just print it and return;
    {
        cout<<t<<endl;
        return;
    }

    if (a[idx] + curr <= sum)
    {
        string temp = t;
        if (temp.size() != 0) // just formatting the output
            temp.push_back('-');
        temp.append(to_string(a[idx])); // instead of backtracking temp variable is used;

        solve(idx + 1, a, sum, curr + a[idx], temp);
        solve(idx + 1, a, sum, curr, t);
    }
    else
    solve(idx + 1, a, sum, curr, t);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;
    solve(0, a, x, 0, "");
    return 0;
}
/*
Approach 1  : Generate all subsets and print only those whose sum = x
Approach 2 : Using backtracking : It can be optimised  (In recursion tree, discard the exploration of nodes from where you are sure than u will not get answer);
             Print all subset of given array whose sum=x;

Example :
==> Input :
6
5 10 12 13 15 18
30
==> Output :
5-10-15
5-12-13
12-18
*/
