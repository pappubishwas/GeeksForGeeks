//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int one=-1,zero=-1,two=-1,ans=INT_MAX;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0') zero=i;
            else if(S[i]=='1') one=i;
            else two=i;
            if(one!=-1 && two !=-1 && zero!=-1){
                int mn=min({one,two,zero});
                int mx=max({one,two,zero});
                ans=min(ans,(mx-mn+1));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends