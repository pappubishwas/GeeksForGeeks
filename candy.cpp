//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCandy(int N, vector<int> &ra) {
        // code here
        vector<int> ans(N,1);
        for(int i=1;i<N;i++){
            if(ra[i]>ra[i-1])
            ans[i]=ans[i-1]+1;
        }
        for(int i=N-2;i>=0;i--){
            if(ra[i]>ra[i+1])
            ans[i]=max(ans[i+1]+1,ans[i]);
        }
        return accumulate(begin(ans),end(ans),0LL);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends