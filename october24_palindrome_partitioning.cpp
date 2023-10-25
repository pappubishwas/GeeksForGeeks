//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    bool ispalindrome(string s,int i,int j){
        while(i<=j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    int palindromicPartition(string s)
    {
        // code here
        int n=s.size();
        int dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int row=0,col=gap;row<n-gap;row++,col++){
                if(ispalindrome(s,row,col)) dp[row][col]=0;
                else{
                    dp[row][col]=INT_MAX;
                    for(int k=row;k<col;k++){
                        dp[row][col]=min(dp[row][col],1+dp[row][k]+dp[k+1][col]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
}; 

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends