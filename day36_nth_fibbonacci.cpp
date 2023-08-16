//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int nthFibonacci(int n){
        // code here
        int mod=1000000007;
        int n1=1,n2=1,temp;
        if(n==1)
        return 1;
        if(n==2)
        return 1;
        int i=3;
        while(i<=n){
            temp=(n1+n2)%mod;
            n1=n2;
            n2=temp;
            i++;
        }
        temp=temp%mod;
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends