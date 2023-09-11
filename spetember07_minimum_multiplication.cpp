//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0;

        vector<int> vis(1000005, 0);
        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = 1;
        while (!q.empty())
        {
            int x = q.front().first;
            int dist = q.front().second;
            q.pop();
            for (int i = 0; i < arr.size(); i++)
            {
                int new_node = (arr[i] * x) % 100000;
                if (new_node == end)
                {
                    return dist + 1;
                }
                if (!vis[new_node])
                {
                    q.push({new_node, dist + 1});
                    vis[new_node] = 1;
                }
            }
        }
        return -1;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code EndsF