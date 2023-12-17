//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        if (n == 1)
            return arr[0];
        int prev = 0, curr = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (prev + arr[i] > curr)
            {
                int t = curr;
                curr = prev + arr[i];
                prev = t;
            }
            else
            {
                prev = curr;
            }
        }
        return max(prev, curr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code EndsF