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
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int maximumBattalions(int N, vector<string> &names) {
        // code here
        vector<pair<int,int>> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<N;i++){
            if(mp[names[i]]==0)
            {
                mp[names[i]]=i+1;
                ans.push_back({i,i});
            }else{
                ans.push_back({mp[names[i]]-1,i});
            }
        }
        sort(begin(ans),end(ans));
        int res=1;
        int t=ans[0].second;
        for(int i=1;i<ans.size();i++){
            if(t<ans[i].first){
                res++;
            }
            if(t<ans[i].second)
            t=ans[i].second;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<string> names(N);
        Array::input(names,N);
        
        Solution obj;
        int res = obj.maximumBattalions(N, names);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends