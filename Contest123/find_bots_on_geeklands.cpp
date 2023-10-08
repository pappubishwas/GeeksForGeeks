//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends
class Solution
{
public:
    bool prime(int p)
    {
        if (p == 1)
            return false;
        for (int i = 2; i < p; i++)
            if (p % i == 0)
                return false;

        return true;
    }
    vector<int> findBots(vector<string> &usernames, int n)
    {
        // code here
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int m = usernames[i].size();
            set<char> s;
            for (int j = 0; j < m; j = j + 2)
            {
                s.insert(usernames[i][j]);
            }
            int p = s.size();
            if (prime(p))
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
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

        vector<string> usernames(n);
        Array::input(usernames, n);

        Solution obj;
        vector<int> res = obj.findBots(usernames, n);
        for (auto ele : res)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends