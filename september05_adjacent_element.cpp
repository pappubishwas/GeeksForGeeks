#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>> edges) {
        // Code here
        vector<set<int>> ans(V);
        for(auto& m : edges){
            int f = m.first, s = m.second;
            ans[f].insert(s);
            ans[s].insert(f);
        }
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++) {
            adj[i] = vector<int>(ans[i].begin(), ans[i].end());
        }
        return adj;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i = 0; i < V; i++) {
            sort(adj[i].begin(), adj[i].end());
            for(auto it : adj[i])
                cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}
