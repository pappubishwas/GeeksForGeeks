//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dikstra(int n,vector<pair<int,int>>adj[],int thr,int src){
        priority_queue<int>q;
        q.push(src);
        
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        while(!q.empty()){
            int node=q.top();
            q.pop();
            
            for(auto x:adj[node]){
                int nbr=x.first;
                int wt=x.second;
                if(dist[nbr]>wt+dist[node])
                {
                    dist[nbr]=wt+dist[node];
                    q.push(nbr);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(dist[i]<=thr) count++;
        }
        return count;
    }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int>freq(n);
        
        for(int i=0;i<n;i++){
            freq[i]=dikstra(n,adj,distanceThreshold,i);
        }
        
        int mnfrq=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(mnfrq>=freq[i]){
                mnfrq=freq[i];
                ans=i;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends