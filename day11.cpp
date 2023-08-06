//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
         string R = A;
    reverse(R.begin(), R.end());
 

    int dp[A.length() + 1][R.length() + 1];

    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= R.length(); j++) {
            if (A[i - 1] == R[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
 

    return dp[A.length()][R.length()];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends