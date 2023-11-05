//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> mp(max_val + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i <= max_val; i++) {
            if (mp[i] != 0) pq.push({mp[i], i});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            auto l = pq.top();
            pq.pop();
            ans.push_back(l.second);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends