//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code here
        vector<int> ans;
        int n=mat.size();
        
            for(int j=0;j<n;j++){
                int x=0,y=j;
                while(x<n && y>=0){
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            for(int j=1;j<n;j++){
                int x=j,y=n-1;
                while(x<n && y>=0){
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends