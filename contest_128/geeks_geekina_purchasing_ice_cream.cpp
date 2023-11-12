//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long findGoodPairs(vector<int> a, int n, int k)
    {
        // code here
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < a.size(); i++)
        {
            mp[a[i]].push_back(i);
        }
        for (auto &v : mp)
        {
            sort(mp[v.first].begin(), mp[v.first].end());
        }
        long long int res = 0;
        for (auto &v : mp)
        {
            vector<int> temp = v.second;
            int l = 0, r = 1;
            while (r < temp.size() && l < temp.size())
            {
                if (abs(temp[l] - temp[r]) >= k)
                {
                    res += ((temp.size() - r));
                    l++;
                }
                else
                {
                    r++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.findGoodPairs(a, n, k) << "\n";
    }
    return 0;
}

// } Driver Code Ends