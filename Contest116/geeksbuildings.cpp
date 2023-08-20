//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    long long maximum_energy(int n, vector<int> &heights) {
        int i = n - 2;
        unordered_map<long long, long long> fq;
        fq[heights[n - 1]] = heights[n - 1];
        long long sum = heights[0], tempsum = heights[0];
        while (i >= 0) {
            int j = i + 1,c=0;
            tempsum = heights[i];
            int temp = heights[i];
            while (j < n) {
                if (temp < heights[j]) {
                    long long t = fq[heights[j]];
                    tempsum = tempsum ^ t;
                    fq[temp] = tempsum;
                    c=1;
                    break;
                }
                
                j++;
            }
            if(c==0){
                    fq[temp] = tempsum;
            }
            i--;
        }
        for (const auto& entry : fq) {
            long long p = entry.second;
            sum = max(sum, p);
        }
        return sum;
    }
};



//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++ ){
            cin >> heights[i];
        }
        Solution obj;
        cout << obj.maximum_energy(n, heights) << endl;
    }
}
// } Driver Code Ends