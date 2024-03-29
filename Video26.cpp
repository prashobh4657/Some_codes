#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool getPath(node *root, vector<int> &arr, int x) //hypothesis : returns bool value tell whether path exist or not, and also update arr with x if path exist;
{
    if (root == NULL)
        return false;

    if (root->data == x)
    {
        arr.push_back(x);
        return true;
    }
    arr.push_back(root->data);
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;
}
int main()
{
    int x;
    cin >> x;
    node *root = new node(7);
    root->left = new node(4);
    root->left->left = new node(x);
    vector<int> arr;
    if (getPath(root, arr, x))
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
            if (i != arr.size() - 1)  //just formatting the output
                cout << "->";
        }
    }

    return 0;
}
