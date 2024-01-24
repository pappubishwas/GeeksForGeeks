//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int find(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u],parent);
    }
    void unionadj(int u,int v,vector<int>&parent){
        u=find(u,parent);
        v=find(v,parent);
        if(u!=v){
            parent[u]=v;
        }
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(n==1 && m==0) return 1;
        vector<int>parent(n);
        set<int> s;
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<m;i++){
            if(find(adj[i][0],parent)==find(adj[i][1],parent)) return 0;
            unionadj(adj[i][0],adj[i][1],parent);
            s.insert(adj[i][0]);
            s.insert(adj[i][1]);
        }
        if(s.size()<n) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends