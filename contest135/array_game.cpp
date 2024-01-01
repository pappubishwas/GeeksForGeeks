//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
	    // code here
	    int res=0;
	    for(int i=0;i<n;i++){
	        res++;
	        for(int j=0;j<arr.size();j++){
	            if(brr[i]==arr[0]){
	                arr.erase(arr.begin());
	                break;
	            }else{
	                int t=arr[0];
	                arr.erase(arr.begin());
	                arr.push_back(t);
	            }
	            res++;
	        }
	    }
	    return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        int n;
        cin >> n;
        vector<int> arr(n), brr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }
        Solution obj;
        cout << obj.min_operations(n, arr, brr) << endl;
    }
}

// } Driver Code Ends