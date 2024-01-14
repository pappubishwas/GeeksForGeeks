//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalCount(int n, string s) {
        // code here
        int mod=1e9+7,res=n;
        char c=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==c)
            res=(res+n-i)%mod;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        cin>>n;
        
        
        string s;
        cin>>s;

        Solution obj;
        int res = obj.totalCount(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends