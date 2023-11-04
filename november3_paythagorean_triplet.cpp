//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool checkTriplet(int arr[], int n) {
	    for(int i=0;i<n;i++) arr[i]=pow(arr[i],2);
	    unordered_map<int,bool> mp;
	    for(int i=0;i<n;i++)  mp[arr[i]]=true;
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++)
	        {
	            int sum=arr[i]+arr[j];
	            if(mp.count(sum)) return true;
	        }
	    }
	    return false;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends