//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
          vector<int> al;
        vector<int> dx1 = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy1 = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> dx2 = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
        vector<int> dy2 = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};

        for (int x = 0; x < q; x++) {
            int sum = 0;
            int i = queries[x][1];
            int j = queries[x][2];

            if (queries[x][0] == 1) {
                for (int k = 0; k < dx1.size(); k++) {
                    int n_x = i + dx1[k];
                    int n_y = j + dy1[k];
                    if (isSafe(n_x, n_y, n, m))
                        sum += mat[n_x][n_y];
                }
            } else {
                for (int k = 0; k < dx2.size(); k++) {
                    int n_x = i + dx2[k];
                    int n_y = j + dy2[k];
                    if (isSafe(n_x, n_y, n, m))
                        sum += mat[n_x][n_y];
                }
            }
            al.push_back(sum);
        }
        return al;
    }

    static bool isSafe(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends