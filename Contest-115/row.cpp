//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int completeRows(int n) {
       // code here
        int r=0,sum=1;
        while(n>=sum){
            n=n-sum;
            sum=sum+1;
            r++;
        }
        return r;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        Solution obj;
        int res = obj.completeRows(n);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends