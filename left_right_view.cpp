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

// Right View : Reverse preorder : root->right->left;
void rev_preorder(node *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->data);
    rev_preorder(root->right, level + 1, res);
    rev_preorder(root->right, level + 1, res);
}
vector<int> rightView(node *root)
{
    vector<int> res;
    rev_preorder(root, 0, res);
    return res;
}

int main()
{

    return 0;
}