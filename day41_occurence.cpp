//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    void recursion(int arr[], int &dp, int start, int end, int x)
    {
        if (start > end || x < arr[start] || x > arr[end])
            return;
        int med = (start + end) / 2;
        if (x == arr[med])
        {
            dp++;
            recursion(arr, dp, start, med - 1, x);
            recursion(arr, dp, med + 1, end, x);
        }
        else if (x > arr[med])
        {
            recursion(arr, dp, med + 1, end, x);
        }
        else
            recursion(arr, dp, start, med - 1, x);
    }
    int count(int arr[], int n, int x)
    {
        // code here
        int dp;
        dp = 0;
        recursion(arr, dp, 0, n - 1, x);
        return dp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends