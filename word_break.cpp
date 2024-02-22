//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool solve(string s,unordered_map<string,int>&mp,int idx){
        if(idx>=s.size()) return true;
        
        for(int i=idx;i<s.size();i++){
            string sb=s.substr(idx,i-idx+1);
            if(mp[sb]>0){
                if(solve(s,mp,i+1)) return true;
            }
        }
        return false;
    }
    
    int wordBreak(int n, string s, vector<string> &dict) {
        //code here
        unordered_map<string,int>mp;
        for(int i=0;i<dict.size();i++){
            mp[dict[i]]++;
        }
        return solve(s,mp,0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends