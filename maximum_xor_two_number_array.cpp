//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class TrieNode {
public:
    TrieNode* zero;
    TrieNode* one;

    TrieNode() : zero(nullptr), one(nullptr) {}
};

class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        int maxXor=0;
        TrieNode *root=new TrieNode();
        
        for(int i=0;i<n;i++){
            insert(root,arr[i]);
        }
        for(int i=0;i<n;i++){
            maxXor=max(maxXor,findMaxXor(root,arr[i]));
        }
        return maxXor;
    }
    private:
    
    void insert(TrieNode* root,int n){
        TrieNode *curr=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(bit==0){
                if(curr->zero==nullptr)
                curr->zero=new TrieNode();
                curr=curr->zero;
            }else{
                if(curr->one==nullptr)  curr->one=new TrieNode();
                curr=curr->one;
            }
        }
    }
    int findMaxXor(TrieNode*root,int n){
        TrieNode* curr=root;
        int maxXor=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(bit==0){
                if(curr->one!=nullptr){
                    maxXor |=(1<<i);
                    curr=curr->one;
                }else
                curr=curr->zero;
            }else{
                if(curr->zero!=nullptr){
                    maxXor |=(1<<i);
                    curr=curr->zero;
                }else
                curr =curr->one;
            }
        }
        return maxXor;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends