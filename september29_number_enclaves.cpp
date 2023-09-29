//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void markboundary(vector<vector<int>> &grid, vector<vector<bool>> &visited, int k, int d)
    {
        int n = grid.size(), m = grid[0].size();
        visited[k][d] = true;
        stack<pair<int, int>> st;
        st.push({k, d});
        while (!st.empty())
        {
            pair<int, int> p = st.top();
            st.pop();
            if (p.first > 0 && grid[p.first - 1][p.second] == 1 && visited[p.first - 1][p.second] == false)
            {
                visited[p.first - 1][p.second] = true;
                st.push({p.first - 1, p.second});
            }
            if (p.first < n - 1 && grid[p.first + 1][p.second] == 1 && visited[p.first + 1][p.second] == false)
            {
                visited[p.first + 1][p.second] = true;
                st.push({p.first + 1, p.second});
            }
            if (p.second > 0 && grid[p.first][p.second - 1] == 1 && visited[p.first][p.second - 1] == false)
            {
                visited[p.first][p.second - 1] = true;
                st.push({p.first, p.second - 1});
            }
            if (p.second < m - 1 && grid[p.first][p.second + 1] == 1 && visited[p.first][p.second + 1] == false)
            {
                visited[p.first][p.second + 1] = true;
                st.push({p.first, p.second + 1});
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1 && visited[0][i] == false)
            {
                markboundary(grid, visited, 0, i);
            }
            if (grid[n - 1][i] == 1 && visited[n - 1][i] == false)
            {
                markboundary(grid, visited, n - 1, i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1 && visited[i][0] == false)
            {
                markboundary(grid, visited, i, 0);
            }
            if (grid[i][m - 1] == 1 && visited[i][m - 1] == false)
            {
                markboundary(grid, visited, i, m - 1);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    count++;
                }
            }
        }

        return count; // You should return the actual result
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends