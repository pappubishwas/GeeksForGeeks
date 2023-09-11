//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void floodFillUtil(vector<vector<char>> &mat, int x, int y, char prevV, char newV, int M, int N)
    {
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
        if (mat[x][y] != prevV)
            return;

        mat[x][y] = newV;

        floodFillUtil(mat, x + 1, y, prevV, newV, M, N);
        floodFillUtil(mat, x - 1, y, prevV, newV, M, N);
        floodFillUtil(mat, x, y + 1, prevV, newV, M, N);
        floodFillUtil(mat, x, y - 1, prevV, newV, M, N);
    }

    vector<vector<char>> fill(int M, int N, vector<vector<char>> &mat)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (mat[i][j] == 'O')
                    mat[i][j] = '-';

        for (int i = 0; i < M; i++)
        {
            if (mat[i][0] == '-')
                floodFillUtil(mat, i, 0, '-', 'O', M, N);
            if (mat[i][N - 1] == '-')
                floodFillUtil(mat, i, N - 1, '-', 'O', M, N);
        }

        for (int i = 0; i < N; i++)
        {
            if (mat[0][i] == '-')
                floodFillUtil(mat, 0, i, '-', 'O', M, N);
            if (mat[M - 1][i] == '-')
                floodFillUtil(mat, M - 1, i, '-', 'O', M, N);
        }

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (mat[i][j] == '-')
                    mat[i][j] = 'X';

        return mat;
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
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends