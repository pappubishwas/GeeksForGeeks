//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define infy 999999999
    long long int dp[30][30];
    int s[30][30];
    void print_optimal(int i, int j, int s[30][30], string& ans) {
        
        if (i == j) {
            ans += (char)('A' + i - 1);
        } else {
            ans += "(";
            print_optimal(i, s[i][j], s, ans);
            print_optimal(s[i][j] + 1, j, s, ans);
            ans += ")";
        }
    }
    string matrixChainOrder(int p[], int n){
        // code here
        n--;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                dp[i][i]=0;
                dp[i][j]=infy;
                s[i][j]=0;
            }
        }
        
        long long int q;
        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                if(i==j) dp[i][j]=0;
                else{
                    for(int k=i;k<j;k++){
                        q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                        if(q<dp[i][j]){
                            dp[i][j]=q;
                            s[i][j]=k;
                        }
                    }
                }
            }
        }
        
    string ans="";

    print_optimal(1,n,s,ans);
    cout<<ans;
    return ans;
    }
};



//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends