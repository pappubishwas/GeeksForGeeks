//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution 
{
public:
    vector<int> depth;
    vector<vector<int>> dp;
    vector<vector<int>> g;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        dp[u][0] = p;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        for (int j = 19; j >= 0; --j) {
            if (depth[u] - (1 << j) >= depth[v]) {
                u = dp[u][j];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = 19; j >= 0; --j) {
            if (dp[u][j] != -1 && dp[u][j] != dp[v][j]) {
                u = dp[u][j];
                v = dp[v][j];
            }
        }

        return dp[u][0];
    }

    vector<long long> calcPairs(int N, vector<int> p) {
        // Creating the graph
        g.resize(N);
        for (int i = 0; i < N; ++i) {
            if (p[i] != -1) {
                g[i].push_back(p[i]);
                g[p[i]].push_back(i);
            }
        }

        // Preparing depth and dp arrays
        depth.resize(N);
        dp.assign(N, vector<int>(20, -1));

        dfs(0, -1, 0);
        for (int j = 1; j < 20; ++j) {
            for (int i = 0; i < N; ++i) {
                if (dp[i][j - 1] != -1) {
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }

        // Calculating number of pairs with LCA = x
        vector<long long> ans(N - 1, 0);
        for (int u = 1; u < N; ++u) {
            for (int v = u + 1; v < N; ++v) {
                int x = lca(u, v);
                ans[x - 1]++;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main()
{

    int t;
	cin >>t ;
    while(t--)
    {
        int V;
    	cin >> V ;

    	vector<int> par(V) ;
        for(int  i = 0 ; i < V ; ++i) {
            cin >> par[i] ;
        }
        Solution obj;
        vector<long long>ans=obj.calcPairs(V, par);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends