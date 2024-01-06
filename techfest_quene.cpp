//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int> v(b+1,-1);
	    v[0]=0; v[1]=1;
	    for(int i=2;i<=b;i++){
	        if(v[i]==-1){
	            for(int x=i;x<=b;x+=i)
	               v[x]=i;
	        }
	    }
	    
	   // for(int i=0;i<=b;i++)
	   // cout<<v[i]<<" ";
	   
	    int ans=0;
	    for(int i=a;i<=b;i++){
	        int x=i;
	        while(x>1){
	            ans++;
	            x=x/v[x];
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends