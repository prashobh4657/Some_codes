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

// Given operation : You can increment any node by (+1) any times;
void changeTree(node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else // To avoid shortage of data during coming back, we give bigger values to root->left and root->right so that we have sufficient data;Consider example z1;
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;

    if (root->left || root->right) // It means it is not leaf then,
        root->data = total;
}

/*
z1 : dry run on this example
   50
   /\
  2  3
 /\  /\
1 4  5 6


*/
