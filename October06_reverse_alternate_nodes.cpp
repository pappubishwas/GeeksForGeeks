//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* A linked list node */

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

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert()
{
    int n, value;
    cin >> n;
    struct Node *temp;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution
{
public:
    Node *reverselist(struct Node *head)
    {
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    void rearrange(struct Node *odd)
    {
        // add code here
        struct Node *even = NULL, *temp1, *temp2;
        if (odd->next == NULL)
            return;

        temp1 = odd;
        while (temp1 != NULL and temp1->next != NULL)
        {
            if (even == NULL)
            {
                even = odd->next;
                temp2 = even;
                temp1->next = temp1->next->next;
                if (temp1->next != NULL)
                    temp1 = temp1->next;
                // temp2->next=NULL;
            }
            else
            {
                temp2->next = temp1->next;
                temp1->next = temp1->next->next;
                temp2 = temp2->next;
                if (temp1->next != NULL)
                    temp1 = temp1->next;
                // temp2->next=NULL;
            }
        }
        temp2->next = NULL;
        Node *p = reverselist(even);
        temp1->next = p;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends