//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int n,dp[1001][1001];
    char ch[1001][1001];
    int printlcs(string s,int i,int j){
        if(i==0 || j==0) return 0;
        if(ch[i][j]=='c'){
            return 1+printlcs(s,i-1,j-1);
        }else if(ch[i][j]=='u')
           return  printlcs(s,i-1,j);
        else 
           return printlcs(s,i,j-1);
    }
    void lcs(string s1,string s2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ch[i][j]='c';
                }else if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    ch[i][j]='u';
                }else{
                    dp[i][j]=dp[i][j-1];
                    ch[i][j]='l';
                }
            }
        }
    }
    int minimumNumberOfDeletions(string s1) { 
        // code here
        string s2=s1;
        reverse(s2.begin(),s2.end());
        n=s1.size();
        memset(dp,0,sizeof(dp));
        lcs(s1,s2);
        return n-printlcs(s1,n,n);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends