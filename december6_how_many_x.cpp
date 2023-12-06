//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int findX(int l,int x){
    int c=0;
    while(l>0){
        int rem=l%10;
        if(rem==x) c++;
        l/=10;
    }
    return c;
}
    int countX(int L, int R, int X) {
        // code here
        int count=0;
        L++;
        while(L<R){
           count+=findX(L,X);
           
           L++;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends