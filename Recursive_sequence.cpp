//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
public:
    int mod=1e9+7;

    long long f(int term, int start, int n){
        if(term > n){
            return 0;
        }
        
        long long int ans=1;
        for(int i=0;i<term;i++){
            ans=ans*start;
            ans=ans%mod;
            start++;
        }
        
        ans=ans+f(term+1, start, n);
        ans=ans%mod;
        
        return ans;
    }

    long long sequence(int n){
        // code here
        long long ans= f(1, 1, n);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends