//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *compute(Node *head)
    {
        // your code goes here
        stack<Node*> pt;
        Node *temp = head, *prev = nullptr; // Initialize prev as nullptr
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->data < temp->next->data)
            {
                if (temp==head)
                {
                    head = temp->next;
                    temp=head;
                    prev=head;
                }
                else
                {
                    prev->next = temp->next;
                    temp=prev;
                    if(!pt.empty()){
                        prev=pt.top();
                        pt.pop();
                    }
                }
            }
            else
            {
                pt.push(prev);
                prev = temp;
                temp = temp->next;
            }
            
        }
        return head;
    }
};



   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends