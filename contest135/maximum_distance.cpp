//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int N, int a, vector<int> x) {
        // code here
        vector<int>diff(N);
        for(int i=0;i<N;i++){
            diff[i]=abs(x[i]-a);
        }
        sort(begin(diff),end(diff));
        return diff[N-1]+diff[N-2];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {

        int N, a;
        cin >> N >> a;


        vector<int> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];

        Solution ob;
        cout << ob.solve(N, a, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends