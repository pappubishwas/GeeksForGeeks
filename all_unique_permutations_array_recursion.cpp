//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    void solve(int i,vector<int>&a,int n,vector<int>&t,vector<int>&taken){
        if(i==n) ans.push_back(t);
        vector<int>curr_taken(11);
        for(int j=0;j<n;j++){
            if(!taken[j] && !curr_taken[a[j]]){
                t.push_back(a[j]);
                taken[j]=1;
                curr_taken[a[j]]=1;
                solve(i+1,a,n,t,taken);
                taken[j]=0;
                t.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<int> t,taken(n);
        
        solve(0,arr,n,t,taken);
        sort(begin(ans),end(ans));
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends