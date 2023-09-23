//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  void binarySearch(int arr[], int n, int x, int l, int h, int &max1,
                    int &min1) {
    if (l > h)
      return;
    int mid = (l + h) / 2;
    if (arr[mid] == x) {
      max1 = max(max1, mid);
      min1 = min(min1, mid);
      binarySearch(arr, n, x, l, mid - 1, max1, min1);
      binarySearch(arr, n, x, mid + 1, h, max1, min1);
    } else if (arr[mid] > x)
      binarySearch(arr, n, x, l, mid - 1, max1, min1);
    else
      binarySearch(arr, n, x, mid + 1, h, max1, min1);
  }

public:
  vector<int> find(int arr[], int n, int x) {
    // code here
    vector<int> ans;
    int max1 = -1, min1 = 1000000009;
    binarySearch(arr, n, x, 0, n - 1, max1, min1);
    if (max1 == -1) {
      ans.push_back(-1);
      ans.push_back(-1);
      return ans;
    }
    ans.push_back(min1);
    ans.push_back(max1);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int arr[n], i;
    for (i = 0; i < n; i++)
      cin >> arr[i];
    vector<int> ans;
    Solution ob;
    ans = ob.find(arr, n, x);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}

// } Driver Code Ends