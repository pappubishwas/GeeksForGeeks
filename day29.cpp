//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Complete this function

    vector<string> permutation(string S)
    {
        vector<string> ans;
        int N = S.length();
        backtrack(S, 0, N - 1, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void backtrack(string s, int idx, int N, vector<string> &ans)
    {
        if (idx == N)
            ans.push_back(s);
        else
        {
            for (int i = idx; i <= N; i++)
            {
                swap(s[idx], s[i]);
                backtrack(s, idx + 1, N, ans);
                swap(s[idx], s[i]);
            }
        }
    }

    // void backtrack(string curr, vector<string>& ans, string nums) {
    //     if (curr.size() == nums.size()) {
    //         ans.push_back(curr);
    //         return;
    //     }

    //     for (char num: nums) {
    //         // if (find(curr.begin(), curr.end(), num) == curr.end()) {
    //             curr.push_back(num);
    //             backtrack(curr, ans, nums);
    //             curr.pop_back();
    //         //}
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
        string S;
        cin >> S;
        Solution ob;
        vector<string> vec = ob.permutation(S);
        for (string s : vec)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends