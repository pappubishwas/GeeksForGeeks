//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long count101(long long n) {
        // code here
        vector<int>binary;
        while(n>0){
        binary.push_back(n%2);
        n/=2;
        }
        reverse(binary.begin(),binary.end());
        long long ans=0;
        for(int i=0;i<binary.size();i++){
            if(binary[i]==1){
            for(int j=i+1;j<binary.size();j++){
            if(binary[j]==0){
            for(int k=j+1;k<binary.size();k++){
            if(binary[k]==1){
                ans+=1;
            }
        }
            }
        }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long n;
        scanf("%lld",&n);
        
        Solution obj;
        long long res = obj.count101(n);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends