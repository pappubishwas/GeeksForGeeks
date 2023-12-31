//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    ll zero=1,one=1,mod=1e9+7;
	    if(n==1) return 2;
	    int i=2;
	    while(i<n){
	        int t=zero;
	        zero=(zero+one)%mod;
	        one=t%mod;
	        i++;
	    }
	    return ((2*zero)%mod + one)%mod;

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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends