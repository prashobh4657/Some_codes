#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void method3(int idx, string s, vector<string> &ans) // Hypothesis : It will print all substrings of string s considering from index=idx to last;
{
    if (idx == s.size())
        return;

    // Print all substring starting from index=idx;
    for (int i = idx; i < s.size(); i++)
    {
        string temp;
        for (int j = idx; j <= i; j++)
            temp.push_back(s[j]);

        ans.push_back(temp);
        temp.clear();
    }

    method3(idx + 1, s, ans);
    return;
}
vector<string> method2(string s, int idx) // Print all substrings of string considering from from 0 to idx;
{
    vector<string> result;
    if (idx == -1)
        return result;
    if (idx == 0)
    {
        string temp;
        temp.push_back(s[idx]);
        result.push_back(temp);
        return result;
    }

    vector<string> temp = method2(s, idx - 1);
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i][temp[i].size() - 1] == s[idx - 1]) // if temp[i] string has last character = s[idx-1] then only include s[idx] because substring should contigous
        {
            result.push_back(temp[i]); // As it is
            temp[i].push_back(s[idx]);
            result.push_back(temp[i]); // Pushing last character also;
        }
        else // In this case s[idx] can't be appended to temp[i] to make valid substring;
        {
            result.push_back(temp[i]);
        }
    }
    string special; // It is the substring which is having only single character which s[idx] itself;
    special.push_back(s[idx]);
    result.push_back(special);
    return result;
}
vector<string> method1(string s)
{
    vector<string> substrings;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string temp;
            for (int k = i; k <= j; k++)
                temp.push_back(s[k]);

            substrings.push_back(temp);
            temp.clear();
        }
    }
    return substrings;
}
int main()
{
    string s;
    cin >> s;

    vector<string> substring1 = method1(s);  //ITERATION
    vector<string> substring2 = method2(s, s.size() - 1);   //HEAD RECURSION
    vector<string> substring3;
    method3(0, s, substring3);  //TAIL RECURSION
    if (substring1 == substring2)
        cout << "YES" << endl;
    if (substring1 == substring3)
        cout << "YES" << endl;
    
    return 0;
}
