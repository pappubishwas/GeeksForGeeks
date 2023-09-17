//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return list containing first n fibonacci numbers.
    void fibbo(vector<long long> &ans, int k, int n)
    {
        if (k >= n)
            return;
        ans.push_back(ans[k - 1] + ans[k - 2]);
        fibbo(ans, k + 1, n);
    }
    vector<long long> printFibb(int n)
    {
        vector<long long> ans;
        ans.push_back(1);
        if (n == 1)
            return ans;
        ans.push_back(1);
        fibbo(ans, 2, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of elements
        int n;
        cin >> n;
        Solution obj;
        // calling function printFibb()
        vector<long long> ans = obj.printFibb(n);

        // printing the elements of vector
        for (long long i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends