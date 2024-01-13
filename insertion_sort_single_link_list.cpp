//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node* t1=head,*t2=head->next,*temp1=head,*temp2=head;
        while(t2!=NULL){
            temp1=head;
            t1=head;
            while(t1!=NULL && t1!=t2){
                if(t1->data>t2->data){
                    if(t1==head){
                        head=t2;
                        temp2->next=t2->next;
                        t2->next=t1;
                        t2=temp2;
                    }else{
                        temp2->next=t2->next;
                        temp1->next=t2;
                        t2->next=t1;
                        t2=temp2;
                    }
                    break;
                }
                temp1=t1;
                t1=t1->next;
            }
            //if(t2==NULL) break;
            temp2=t2;
            t2=t2->next;
        }
        return head;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends