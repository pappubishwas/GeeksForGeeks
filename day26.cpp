//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<int> inDegree(N, 0); // To store the in-degree of each vertex
        vector<vector<pair<int, int>>> adjList(N); // Adjacency list representation of the graph

        // Constructing the adjacency list and calculating in-degree of each vertex
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
            inDegree[v]++;
        }

        // Topological Sorting
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> distance(N, INT_MAX); // To store the shortest distance from source to each vertex
        distance[0] = 0; // Distance to source vertex is 0

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                // Relaxation step (updating the distance if a shorter path is found)
                if (distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }

                // Decrement the in-degree of the neighbor and add it to the queue if in-degree becomes 0
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Converting -1 distances (unreachable) to -1 in the result
        for (int i = 0; i < N; i++) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }

        return distance;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends