//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int countStrings(string s)
    {
        // // Your code goes here
        //     set<string> ans;
        // int N = S.length();
        // backtrack(S, 0, N - 1, ans);
        // sort(ans.begin(),ans.end());
        // return ans.size();
        std::unordered_set<std::string> ans;
        int n = s.size();

        for (int l = 0; l < n; ++l)
        {
            for (int r = l; r < n; ++r)
            {
                std::string temp = s;
                std::reverse(temp.begin() + l, temp.begin() + r + 1);
                ans.insert(temp);
            }
        }

        return ans.size();
    }
    //     void backtrack(string s, int idx, int N, set<string> &ans)
    // {
    //     if (idx == N)
    //         ans.insert(s);
    //     else
    //     {
    //         for (int i = idx; i <= N; i++)
    //         {
    //             swap(s[idx], s[i]);
    //             backtrack(s, idx + 1, N, ans);
    //             swap(s[idx], s[i]);
    //         }
    //     }
    // }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        Solution obj;
        long long int ans = obj.countStrings(s);
        cout << ans << "\n";
    }
}

// } Driver Code Ends