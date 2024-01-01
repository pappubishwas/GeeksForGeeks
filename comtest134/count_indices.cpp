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
    int countIndices(int n, vector<int> &arr) {
        // code here
        vector<int> b(begin(arr),end(arr));
        sort(begin(b),end(b));
        int count=0;

        for(int i=0;i<n;i++){
            if(b[i]!=arr[i]) count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.countIndices(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends