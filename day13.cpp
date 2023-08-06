//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node *start=NULL;
        struct node *thead=NULL;
        struct node *last=NULL;
        struct node *last1=NULL;
        struct node *temp=head;
        int i=1,c=0,j,l;
        if(k==1){
            return head;
        }else{
                    while(temp!=NULL){
          if(i==k){
                 if(c==0){
                    head=temp->next;
                    thead=temp;
                    temp->next=start;
                    temp=head;
                    if(last!=NULL){
                    last1=last;
                    last1->next=NULL;
                    }
                    i=1;
                    c=1;
                 }else{
                    head=temp->next;
                    last1->next=temp;
                    temp->next=start;
                    temp=head;
                    last1=last;
                    last1->next=NULL;
                    i=1;
                 }
          }
          else if(i==1){
            last=temp;
            start=temp;
            temp=temp->next;
            head=temp;
            i++;
          }
          else{
            head=temp->next;
            temp->next=start;
            start=temp;
            temp=head;
            i++;
          }

        }
        }
        if(i!=1){
            last1->next=start;
            last->next=NULL;
        }
        return thead;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends