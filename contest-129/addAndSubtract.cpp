//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int getMaxFreq(int n, vector<int> &a) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]-1]++;
            mp[a[i]+1]++;
        }
        int c=0;
        for(auto it:mp){
            c=max(c,it.second);
        }
        return c;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> A(n);
        Array::input(A,n);
        
        Solution obj;
        int res = obj.getMaxFreq(n, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends