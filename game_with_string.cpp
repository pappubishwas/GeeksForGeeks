//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int> frq(26);
        for(int i=0;i<s.size();i++) frq[s[i]-'a']++;
        
        while(k>0){
            int mx=-1;
            for(int i=0;i<26;i++){
                if(frq[i]>0 && mx==-1){
                    mx=i;
                }else if(frq[i]>frq[mx]){
                    mx=i;
                }
            }
            if(mx==-1)break;
            frq[mx]-=1;
            k--;
        }
        int sm=0;
        for(int i=0;i<26;i++) sm+=pow(frq[i],2);
        return sm;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends