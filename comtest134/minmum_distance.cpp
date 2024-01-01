//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minDist(int x1, int x2, int x3) {
        // code here
        int mn=min({x1,x2,x3});
        int mx=max({x1,x2,x3});
        return abs(mx-mn);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int x1;
        scanf("%d",&x1);
        
        
        int x2;
        scanf("%d",&x2);
        
        
        int x3;
        scanf("%d",&x3);
        
        Solution obj;
        int res = obj.minDist(x1, x2, x3);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends