//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long minOperations(vector<int> A, int N)
    {
        // Code here
        long long int count = 0, sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum < 0)
            {
                count += abs(sum);
                sum = 0;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        Solution ob;
        cout << ob.minOperations(A, N) << "\n";
    }
}
// } Driver Code Ends