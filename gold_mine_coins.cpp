//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int n,m;
    // int dp[501][501];
    // int solve(vector<vector<int>> gold,int i,int j){
    //     if(i<0 || j<0 || i>=n || j>=m) 
    //     return 0;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int updia=solve(gold,i-1,j+1);
    //     int right=solve(gold,i,j+1);
    //     int downdia=solve(gold,i+1,j+1);
        
    //     return dp[i][j]=(gold[i][j]+max(updia,max(right,downdia)));
    // }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // memset(dp,-1,sizeof(dp));
        // n=N;
        // m=M;
        // int result=0;
        // for(int i=0;i<n;i++){
        //     result=max(result,solve(gold,i,0));
        // }
        // return result;
         int ans=0;
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int mx=INT_MIN;
                if(i-1>=0 and j-1>=0)   mx=max(mx,M[i-1][j-1]);
                if(j-1>=0)              mx=max(mx,M[i][j-1]);
                if(i+1<n and j-1>=0)    mx=max(mx,M[i+1][j-1]);
                M[i][j]+=mx;
                ans=max(ans,M[i][j]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends