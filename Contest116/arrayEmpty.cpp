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
        int count=0;
	    while(!arr.empty()){
            count++;
            int fele=arr[0];
            arr.erase(arr.begin());
            if(fele==brr[0])
            brr.erase(brr.begin());
            else
            arr.push_back(fele);
        }
        return count;
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

// } Driver Code EndsB