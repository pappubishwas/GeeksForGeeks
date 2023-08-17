//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        // code here
        vector<int> ans(n);
        if (n == 1)
        {
            ans[0] = num[0] + 1;
            if (ans[0] > 9)
            {
                ans.clear();
                ans.push_back(1);
                ans.push_back(1);
            }
            return ans;
        }
        int s = 0, e = n - 1, rem = 0, k = 0;
        while (s < e)
        {
            if (num[s] > num[e])
            {
                rem = 1;
                ans[s] = num[s];
                ans[e] = num[s];
            }
            else if (num[s] == num[e])
            {
                ans[s] = num[s];
                ans[e] = num[s];
            }
            else
            {
                rem = 1;
                if (e - 1 >= 0)
                {
                    num[e - 1]++;
                    k = e - 1;
                }

                ans[s] = num[s];
                ans[e] = num[s];
            }
            if (ans[s] > 9 || ans[e] > 9)
            {
                rem = 1;
                ans[s - 1]++;
                ans[s] = 0;
                ans[e] = 0;
                ans[e + 1]++;
            }
            s++;
            e--;
        }

        if (num[s] > 9 && s == e)
        {
            rem = 1;
            ans[s - 1]++;
            ans[s + 1]++;
            ans[s] = 0;
        }
        else if (s == e)
        {

            if (k == s || rem == 1)
                ans[s] = num[s];
            else
                ans[s] = num[s] + 1;

            rem = 1;
        }

        if (rem == 0)
        {
            ans.clear();
            ans.push_back(1);
            int i = 1;
            while (i < n)
            {
                ans.push_back(0);
                i++;
            }
            ans.push_back(1);
        }
        s = 0;
        e = n - 1;
        while (s < e)
        {
            if (ans[s] > 9 || ans[e] > 9)
            {
                rem = 1;
                ans[s - 1]++;
                ans[s] = 0;
                ans[e] = 0;
                ans[e + 1]++;
                if (s - 2 >= 0)
                    s = s - 2;
                else
                    s--;
                if (e + 2 < n)
                    e = e + 2;
                else
                    e++;
            }
            s++;
            e--;
        }

        return ans;
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
        int num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends