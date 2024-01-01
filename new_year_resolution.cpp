//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int n;
    int dp[370][2030];
    int solve(int i,int currSum,int coins[]){
        if(currSum!=0 && (currSum%20==0 || currSum%24==0 || currSum==2024)) return dp[i][currSum]=1;
        if(dp[i][currSum]!=-1) return dp[i][currSum];
        
        if(i>=n) return 0;
        
        int taken=solve(i+1,currSum+coins[i],coins);
        if(taken) return dp[i][currSum]=1;
        int not_taken=solve(i+1,currSum,coins);
        return dp[i][currSum]=taken || not_taken;
    }
    public:
    int isPossible(int N , int coins[]) 
    {
        n=N;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,coins);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends