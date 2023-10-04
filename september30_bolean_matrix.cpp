//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void makeOne(vector<vector<int>> &matrix, int k, int d, int n, int m)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[k][i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][d] = 1;
        }
    }

    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        stack<pair<int, int>> ans;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            { // Fix the loop here
                if (matrix[i][j] == 1)
                    ans.push({i, j});
            }
        }
        while (!ans.empty())
        {
            pair<int, int> p = ans.top();
            ans.pop();
            makeOne(matrix, p.first, p.second, n, m);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends