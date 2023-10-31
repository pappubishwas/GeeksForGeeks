//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int findNonZero(int arr[],int i,int n){
        while(i<n){
            if(arr[i]!=0) return i;
            i++;
        }
        return -1;
    }
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int t=-5;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0){
	            if(t==-5)
	            t=findNonZero(arr,i+1,n);
	            else
	            t=findNonZero(arr,t+1,n);
	            
	            if(t==-1) return;
	            arr[i]=arr[t];
	            arr[t]=0;
	            
	        }
	    }
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
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends