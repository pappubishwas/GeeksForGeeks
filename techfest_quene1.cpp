//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int solve(int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        if (n == 2 || n == 3)
        {
            return 1;
        }
        int ans = 0;
        int i = 2;
        while (i * i <= n)
        {
            if (i == 2 || i % 2 == 1)
            {
                while (n % i == 0)
                {
                    ans += 1;
                    n /= i;
                }
            }
            i += 1;
        }
        if (n > 2)
        {
            ans += 1;
        }
        return ans;
    }

    int sumOfPowers(int a, int b)
    {
        int ans = 0;
        int i = a;
        while (i <= b)
        {
            ans += solve(i);
            i += 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        Solution obj;
        int ans = obj.sumOfPowers(a, b);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends