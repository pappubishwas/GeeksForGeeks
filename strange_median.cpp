//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// } Driver Code Ends
// User function Template for C++

/*
Structure of node is like this

struct Node{
    int data;
    Node *left;
    Node *right;
};
*/
class Solution
{
public:
    void inorder(Node *node, vector<int> &list)
    {
        if (node == NULL)
            return;
        inorder(node->left, list);
        list.push_back(node->data);
        inorder(node->right, list);
    }

    int median(Node *node, int k)
    {
        // Your code here
        vector<int> ans;
        inorder(node, ans);
        int h = ans.size(), l = k;
        if (k == h)
            return ans.back();
        if ((h - l + 1) % 2 == 0)
        {
            return (ans[(h + l) / 2 - 1] + ans[((h + l) / 2)]) / 2;
        }
        else
            return ans[(l + h) / 2 - 1];
    }
};

//{ Driver Code Starts.
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        root = newNode(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int main()
{
    int t;
    cin >> t;
    Solution ob;
    while (t--)
    {
        Node *root = NULL;
        int n;
        int k;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        // inorder(root);

        cout << ob.median(root, k) << endl;
    }
    return 0;
}

// } Driver Code Ends