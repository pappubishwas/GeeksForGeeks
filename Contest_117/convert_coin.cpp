//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string flipCoins(int N, string s){
        int count=0;
        for(int i=0;i<N;i++){
            if(s[i]=='0'){
                count++;
            }
        }
        if(count%2==0)
        return "Yes";
        else
        return "No";
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int n; 
        cin >> n ; 
        string s; 
        cin >> s; 
        Solution obj;
        string ans = obj.flipCoins(n , s);
        cout << ans << "\n";
    }
}

// } Driver Code Ends