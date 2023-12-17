//{ Driver Code Starts
//Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
class Solution{   
public:
    long long int totalWays(int n)
    {
        // Write your code here.
        long long int res=1,i=2;
        while(i<=n){
            res*=i;
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        long long int ans=ob.totalWays(n);
        cout<<ans<<endl;
    }
}

// } Driver Code Ends