//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(vector<string>&ans,string s,int one,int zero,int n){
        if(one<zero) return;
        
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        
        solve(ans,s+"1",one+1,zero,n);
        solve(ans,s+"0",one,zero+1,n);
    }
    vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    
	    solve(ans,"",0,0,n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends