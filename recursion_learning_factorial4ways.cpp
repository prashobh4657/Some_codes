/* 1. Recursion two types :
         a. tail
         b. head
        It depends on question like what type will be easy to implement same as like some question can be easily solved using 
        recursion and some can be easily solved using iteration. i guess same case is with tail and head.

    I think (some observations till now),
    -->Some problems can be solved using tail easily and some using head.
    -->Most of backtracking grid-based problems can be easily solved using tail recursion. Generally tail recursion function are of return-type void;
       till now whatever i solved backtracking is just tail recursive.
       Using head-recursion it would be complicated.
       Like problem sudoku solver, n-queen, rat in a maze etc.
    -->The recursive tree which we draw to consider all possibilties as a human ==> unknowingly using tail recursion.
    -->DP problems should be solved using Head-recursion.
       Because after writing tail recursive code ==> it can't be memoized further i guess.
       (because it has lot of parameter so may be by increasing dimension of matrix that can be memoized);

       Proof :
       https://leetcode.com/problems/min-cost-climbing-stairs/

    1. See submission : https://leetcode.com/submissions/detail/673406237/ (Tail recursive)(can't be memoized)
    2. See submission : https://leetcode.com/submissions/detail/673531061/ (Head recursive code)
    3. See submission : https://leetcode.com/submissions/detail/673531535/ (Head recursive memoized)
    4. See submission : https://leetcode.com/submissions/detail/673571601/ (Tabulation) (Transform: Head recurive memoized --> Tabulation)
*/
/*
Below are the 4 recursive ways to calculate factorial 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void fact1(int i, int n, int curr, int &ans) // tail recursion;
{
    if (i == n + 1)
    {
        ans = curr;
        return;
    }
    fact1(i + 1, n, i * curr, ans);
}
void fact2(int i, int n, int curr, int &ans) // tail reverse
{
    if (i == 0)
    {
        curr = 1 * ans;
        return;
    }
    fact2(i - 1, n, curr * i, ans);
}

int fact3(int n) // head;
{
    if (n == 0)
        return 1;
    return n * fact3(n - 1);
}
int fact4(int idx, int n) // reverse head;
{
    if (idx == n + 1)
        return 1; // logically 1 should be return;

    return idx * fact4(idx + 1, n);
}

int main()
{
    int n;
    cin >> n;

    int ans;
    fact1(1, n, 1, ans);
    cout << ans << endl;

    fact2(n, n, 1, ans);
    cout << ans << endl;

    cout << fact3(n) << endl;
    cout << fact4(1, n);

    return 0;
}