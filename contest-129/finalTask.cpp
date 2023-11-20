//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int count_set_bits(int *a, int n) {
        // Write your code here..
        int c=0;
        for(int i=0;i<n;i++){
            int temp=0;
            while(a[i]>0){
                if(a[i]%2==1) temp++;
                a[i]/=2;
            }
            c+=temp;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        Solution sol;
        cout << sol.count_set_bits(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends