//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


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
    unordered_map<string,int> mp;

    int bitwiseAnd(vector<int> &a, int s, int e) {
        string st=to_string(s);
        st+=to_string(e);
        if (mp[st] !=0){
            return mp[st];
        }

        int t = a[s - 1];
        for (int i = s; i < e; i++) {
            t = t & a[i];
        }

        mp[st] = t;
        return t;
    }

    vector<int> minQuery(int N, int Q, vector<int> &A, vector<vector<int>> &qu) {
        vector<int> ans;
        for (int i = 0; i < Q; i++) {
            int t1, t2, t3;
            t1 = bitwiseAnd(A, qu[i][0], qu[i][1]);
            t2 = bitwiseAnd(A, qu[i][2], qu[i][3]);
            t3 = t1 | t2;
            ans.push_back(t3);
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N,Q;cin>>N>>Q;
        
        vector<int> A(N);
        
        for(auto &i:A){
            cin>>i;
        }
        
        int q = Q;
        vector<vector<int>> Queries;
        
        while(q--){
            vector<int> temp(4);
            for(auto &i:temp){
                cin>>i;
            }
            Queries.push_back(temp);
        }
        
        Solution obj;
        vector<int> res = obj.minQuery(N, Q, A, Queries);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends