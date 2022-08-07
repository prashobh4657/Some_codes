#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Best approach;
//  sort the given array;
//  a+b+c=0; ===> b+c=-a;
//  Keep "-a" constant and find two integers such that sum=-a;
//  and also do apply this method only on distinct elements;
//  TC : O(N*N); SC : O(N);
vector<vector<int>> two_pointer_method(vector<int> v) // Best solution
{
    int n = v.size();
    sort(v.begin(), v.end());
    vector<vector<int>> res;
    for (int i = 0; i < v.size() - 2; i++)
    {
        if (i == 0 || (i - 1 >= 0 && v[i] != v[i - 1]))
        {
            // Apply two pointer approach (similar to 2-sum);
            int low = i + 1;
            int high = n - 1;
            int sum = 0 - v[i];
            while (low < high)
            {
                if (v[low] + v[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[low]);
                    temp.push_back(v[high]);
                    while (low < high && v[low] == v[low + 1]) // To ignore all duplicate triplets;
                        low++;
                    while (low < high && v[high] == v[high - 1]) // To ignore all duplicate triplets;
                        high--;
                    low++;
                    high--;
                }
                else if (v[low] + v[high] < sum) // try to increase sum hence low++; (can't do high--);
                    low++;
                else
                    high--;
            }
        }
    }
    return res;
}

vector<vector<int>> hashing_method(vector<int> a) // O((n^2) logn) (logn is for insertion in set) , Space : O(n (unordered_map)+n(set));
{
    int n = a.size();
    // a+b+c=0;
    // Traverse all possible pairs (a,b) and apply hashing on c;
    // Here important point : c=-(a+b);
    // If -(a+b) is equal to a or b itself; then there is condition that frequency of a>1/b>1 respectively; hence to ensure that we will use unordered_map; (also store frequency);
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]--; // This a[i] is used;
        for (int j = 0; j < n; j++)
        {
            mp[a[j]]--;
            if (mp.find(-1 * (a[i] + a[j])) !mp.end())
            {
            }
            mp[a[j]]++; // kind of restoring;
        }
        mp[a[i]]++;
    }
    // keep all triplets in set;
}
vector<vector<int>> brute_force(vector<int> v) // TC : O((n^3) logn), Space : O(n);  (Checking all triplets);
{
    // keep a set to remove duplicacy in triplets;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (v[i] + v[j] + v[j] == 0)
                {
                    // insert triplet {a[i],a[j],a[k]} in set data_structure; (logn insertion);
                }
            }
        }
    }
}
int32_t main()
{
    fio;
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
    }
    return 0;
}
