#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int TotalPairs(vector<int>& nums, int x, int y) {
        int n = nums.size();
        int c = 0;
        
        sort(nums.begin(), nums.end());

        // Map to count the occurrences of each element in the array
        map<int, int> countMap;
        for (int i = 0; i < n; i++) {
            countMap[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            int start = lower_bound(nums.begin(), nums.end(), (x + nums[i] - 1) / nums[i]) - nums.begin();
            int end = upper_bound(nums.begin(), nums.end(), y / nums[i]) - nums.begin();
            
            c += max(0, end - start);

            if (y % nums[i] == 0) {
                // If y is divisible by nums[i], it forms an additional pair (i, y/nums[i])
                c++;
            }

            // Subtract the occurrences of nums[i] from the countMap
            countMap[nums[i]]--;

            // Check for pairs formed by nums[i] and all elements on its right (including itself)
            for (int j = i + 1; j < n; j++) {
                int prod = 1LL * nums[i] * nums[j];
                if (prod >= x && prod <= y) {
                    c++;
                } else {
                    break; // As the array is sorted, no further elements can satisfy the condition
                }
            }

            // Add back the occurrences of nums[i] to the countMap
            countMap[nums[i]]++;
        }

        return c;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.TotalPairs(nums, x, y);
        cout << ans << "\n";
    }
    return 0;
}
