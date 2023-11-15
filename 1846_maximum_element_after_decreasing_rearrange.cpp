#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr.back();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 1, 2, 1};
    int maxElement = sol.maximumElementAfterDecrementingAndRearranging(arr);

    cout << "Maximum element after decrementing and rearranging: " << maxElement << endl;

    return 0;
}
