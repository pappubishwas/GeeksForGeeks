//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        vector<int> a(n);
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=1;i<n;i++){
            if(a[i-1]-i>=0 && mp[a[i-1]-i]==0){
                a[i]=a[i-1]-i;
                mp[a[i-1]-i]=1;
            }else{
                a[i]=a[i-1]+i;
                mp[a[i-1]+i]=1;
            }
        }
        return a;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends