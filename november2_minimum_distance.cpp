//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int f1=-1,f2=-1,maxv=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]==x) f1=i;
            if(a[i]==y) f2=i;
             if(f1!=-1 && f2!=-1){
                  maxv=min(maxv,abs(f1-f2));
             }
            
        }
       
        return maxv==INT_MAX?-1:maxv;
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
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends