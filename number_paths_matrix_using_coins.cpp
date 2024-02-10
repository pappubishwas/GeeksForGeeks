//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long int solve(int i, int j, int n, int k, int currSum, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp) {
        if (i == n-1 && j == n-1) {
            if (currSum+arr[i][j] == k)
                return 1;
            else
                return 0;
        }
        
        if (currSum > k)
            return 0;
        if (dp[i][j][currSum] != -1)
            return dp[i][j][currSum];
        long long sum = 0;
        if (i + 1 < n)
            sum += solve(i + 1, j, n, k, currSum + arr[i][j], arr, dp);
        if (j + 1 < n)
            sum += solve(i, j + 1, n, k, currSum + arr[i][j], arr, dp);
        return dp[i][j][currSum] = sum;
    }

    long long numberOfPath(int n, int k, vector<vector<int>> arr) {
        // Code Here
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));
        return solve(0, 0, n, k, 0, arr, dp);
    }
};



//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends