//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int findMaxAverage(int a[], int n) {
        // add code here.
        int maxval=a[0];
        for(int i=1;i<n;i++) maxval=max(maxval,a[i]);
        return maxval;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution obj;
        cout << obj.findMaxAverage(a, n) << endl;
    }
}

// } Driver Code Ends