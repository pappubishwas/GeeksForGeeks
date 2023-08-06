//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int digitSum(int n)
    {
        int sum = 0, r;
        while (n > 0)
        {
            r = n % 10;
            sum += pow(r, 2);
            n = n / 10;
        }
        return sum;
    }
    bool beautifulNumber(int n)
    {
        // code here
        set<int> s;

        int size = 0, c = 0, i, j, k, sum;
        sum = n;
        while (true)
        {
            sum = digitSum(sum);
            auto pos = s.find(sum);
            if (pos != s.end())
            {
                return false;
            }
            else
                s.insert(sum);
            if (sum == 1)
                break;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        bool res = obj.beautifulNumber(n);
        if (res)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

// } Driver Code Ends