//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

namespace std {
    template <>
    struct hash<std::vector<int>> {
        size_t operator()(const std::vector<int>& v) const {
            size_t hash_value = 0;
            for (int i : v) {
                hash_value ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
            }
            return hash_value;
        }
    };
}

class Solution {
public:
    std::vector<int> repeatedRows(std::vector<std::vector<int>> &matrix, int M, int N) {
        std::unordered_map<std::vector<int>, std::vector<int>> mp;
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<int> t = matrix[i];
            mp[t].push_back(i);
        }
        std::vector<int> ans;
        for (auto &t : mp) {
            std::vector<int> p = t.second;
            std::sort(p.begin(), p.end());
            if (p.size() > 1) {
                ans.insert(ans.end(), 1+p.begin(), p.end());
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends