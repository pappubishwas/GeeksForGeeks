//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int timer=1;
    void dfsbd(int node,int parent,vector<int> &vis,vector<int> adj[],vector<int>&tin,vector<int>&low,vector<vector<int>>&bd){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto currNode:adj[node]){
            if(currNode==parent) continue;

            if(vis[currNode]==0){
                dfsbd(currNode,node,vis,adj,tin,low,bd);
                low[node]=min(low[node],low[currNode]);
                if(low[currNode]>tin[node])
                {
                    if(currNode<node)
                    bd.push_back({currNode,node});
                    else
                    bd.push_back({node,currNode});
                    
                }
            }else{
                low[node]=min(low[node],low[currNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,  vector<int> adj[]) {
        // vector<int> adj[n];
        // for(auto it: connections){
        //     int u=it[0],v=it[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        vector<int> vis(n),tin(n),low(n);
        vector<vector<int>> bd;
        dfsbd(0,-1,vis,adj,tin,low,bd);
        sort(bd.begin(),bd.end());
        return bd;
    }
};

// class Solution {
// public:
// 	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
// 	    // Code here
	    
// 	}
// };


//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends