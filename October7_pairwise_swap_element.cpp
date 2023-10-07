//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
public:
    Node *pairWiseSwap(struct Node *head)
    {
        // The task is to complete this method
        Node *temp1 = head, *temp2 = head;
        while (temp2 != NULL and temp2->next != NULL)
        {
            if (temp1 == head)
            {
                temp2 = head->next->next;
                head = head->next;
                head->next = temp1;
                temp1->next = temp2;
            }
            else
            {
                temp1->next = temp2->next;
                temp2->next = temp1->next->next;
                temp1->next->next = temp2;
                temp1 = temp1->next->next;
                temp2 = temp2->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        map<Node *, int> mp;
        mp[head] = head->data;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
            mp[tail] = tail->data;
        }
        struct Node *failure = new Node(-1);
        Solution ob;
        head = ob.pairWiseSwap(head);
        int flag = 0;
        struct Node *temp = head;
        while (temp)
        {
            if (mp[temp] != temp->data)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag)
            printList(failure);
        else
            printList(head);
    }
    return 0;
}

// } Driver Code Ends