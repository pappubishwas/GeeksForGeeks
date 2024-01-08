//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int minOPs(int n, vector<int> &A)
    {
        //Write Code Here
        map<int,int> freq;
        for(int i=0;i<n;i++) {
            freq[A[i]]++;
        }
        vector<pair<int,int>>s(freq.begin(),freq.end());
        sort(s.begin(),s.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });
        int ans=0,total=0,req=n/2+1;
        for(auto p:s){
            total+=p.second;
            if(total>=req) return ans;
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.minOPs(n,arr)<<endl;
    }
}

// } Driver Code Ends