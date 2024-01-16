//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    int helper(int i,int j,int M,int N){
        if(i==N-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;
        for(int k=2*j;k<=M;k++){
            dp[i][j]+=helper(i+1,k,M,N);
        }
        return dp[i][j];
    }
    int numberSequence(int m, int n){
        // code here
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int j=1;j<m+1;j++){
            res+=helper(0,j,m,n);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends