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
    int seg[4 * 500015];

    void build(int idx, int l, int h, vector<int> &a) {
        if (l == h) {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + h) / 2;
        build(2 * idx + 1, l, mid, a);
        build(2 * idx + 2, mid + 1, h, a);
        seg[idx] = (seg[2 * idx + 1] & seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if (low >= l && high <= r) {
            return seg[idx];
        }
        if (low > r || high < l) return INT_MAX;
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        if (left == INT_MAX) return right;
        if (right == INT_MAX) return left;
        return (left & right);
    }

    vector<int> minQuery(int N, int Q, vector<int> &A, vector<vector<int>> &qu) {
        build(0, 0, N - 1, A);
        vector<int> ans;
        for (int i = 0; i < Q; i++) {
            int t1 = query(0, 0, N - 1, qu[i][0]-1, qu[i][1]-1);
            int t2 = query(0, 0, N - 1, qu[i][2]-1, qu[i][3]-1);
            int t3 = (t1 == INT_MAX || t2 == INT_MAX) ? INT_MAX : (t1 | t2);
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