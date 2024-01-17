//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr,taken(n);
        // Lamda function ,,,,return type void and parameter int..........
        function<void(int)>solve=[&](int p){
            if(p==n){
                ans.push_back(curr);
                return;
            }
            vector<int> curr_taken(11);
            for(int i=0;i<n;i++){
                if(!taken[i] and !curr_taken[arr[i]]){
                    taken[i]=1;
                    curr_taken[arr[i]]=1;
                    curr.push_back(arr[i]);
                    solve(p+1);
                    taken[i]=0;
                    curr.pop_back();
                }
            }
        };
        
        solve(0);
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