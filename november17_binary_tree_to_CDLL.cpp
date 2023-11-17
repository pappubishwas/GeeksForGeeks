//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    head = itr;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<endl;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
public:
    // Function to convert binary tree into circular doubly linked list.
    vector<Node*> solve(Node *root) {
        if (root == NULL) return {};
        
        vector<Node*> temp1 = solve(root->left);
        vector<Node*> temp2 = solve(root->right);
        vector<Node*> res;

        if (!temp1.empty()) {
            root->left = temp1.back();
            temp1.back()->right = root;
            res.push_back(temp1.front());
        } else {
            res.push_back(root);
        }

        if (!temp2.empty()) {
            root->right = temp2.front();
            temp2.front()->left = root;
            res.push_back(temp2.back());
        } else {
            res.push_back(root);
        }

        return res;
    }

    Node* bTreeToCList(Node* root) {
        if (root == NULL) return NULL;

        vector<Node*> ans = solve(root);
        Node* l = ans.front();
        Node* r = ans.back();
        l->left = r;
        r->right = l;
        return l;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node *head = obj.bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}








// } Driver Code Ends