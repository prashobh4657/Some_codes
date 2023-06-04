#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<int> inorderTraversal(node *root) // TC : O(N), SC : O(1);
{
    vector<int> inorder;
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->left == NULL)
        {
            inorder.push_back(temp->data);
            temp = temp->right;
        }
        else
        {
            // First find rightmost node in left-subtree;
            node *prev = temp->left;                           // Move one step left then keep on moving right till last node;
            while (prev->right != NULL && prev->right != temp) // prev->right!=temp condition is important in case if thread already exist then this loop will go in infinite loop; (We have to stop at last node in left-subtree);
                prev = prev->right;

            // Deciding where to move based on whether thread exist or not;
            if (prev->right == NULL) // Thread doesn't exist;
            {
                prev->right = temp; // Make a thread;
                temp = temp->left;  // Go to left-subtree;
            }
            else
            {
                prev->right = NULL;            // Remove thread;
                inorder.push_back(temp->data); // Since left subtree is visited and thread is removed hence now print(temp->val);
                temp = temp->right;            // Go to right-subtree;
            }
        }
    }
    return inorder;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);
    vector<int> inorder;
    inorder = inorderTraversal(root);
    cout << "The Inorder Traversal is: ";
    for (int i = 0; i < inorder.size(); i++)
        cout << inorder[i] << " ";
    return 0;
}