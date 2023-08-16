//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
     long long int  sol(int ind,int amount,int coins[],vector<vector< long long int >> &dp){
       if(ind==0){
           return (amount%coins[0]==0);
            } 
            
            if( dp[ind][amount]!=-1)return dp[ind][amount];

            long long int  nottake=sol(ind-1,amount,coins,dp);
            long long int  take=0;
           if(coins[ind]<=amount){
               take=sol(ind,amount-coins[ind],coins,dp);
           }
          
 return dp[ind][amount]=take+nottake;
}
    long long int count(int coins[], int N, int amount) {
      
        vector<vector< long long int >> dp(N,vector< long long int >(amount+1,-1));
            return sol(N-1,amount,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends