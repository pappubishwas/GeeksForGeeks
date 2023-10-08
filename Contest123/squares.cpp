//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int squares(int N, int X)
    {
        // code here
        long long int count = 1, total = pow(4, N);
        if (X > total)
            return -1;
        int i = 0;
        if (X % 3 <= 1)
            return X / 3;
        else
            return X / 3 + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, X;
        cin >> N >> X;
        Solution obj;
        cout << obj.squares(N, X) << "\n";
    }
}

// } Driver Code Ends