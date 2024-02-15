//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // void dfs(int node, vector<bool>& vis, vector<int>* adj) {
    //     vis[node] = true;
    //     for (auto p : adj[node]) {
    //         if (!vis[p]) {
    //             dfs(p, vis, adj);
    //         }
    //     }
    // }

    int isPossible(vector<vector<int>>& paths) {
        int n = paths.size();
        if (n == 0) {
            return 0; // Handle empty graph
        }

        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            int c=0;
            for (int j = 0; j < n; j++) {
                if (paths[i][j]) {
                    // adj[i].push_back(j);
                    c++;
                }
            }
            if(c%2==1) return 0;
        }

        // vector<bool> vis(n, false);
        // dfs(0, vis, adj);

        // for (int i = 0; i < n; i++) {
        //     if (!vis[i]) {
        //         return 0;
        //     }
        // }

        return 1;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends