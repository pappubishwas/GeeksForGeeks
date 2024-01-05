//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod=1e9+7;
	    long long int t1=1,t2=2,i=1;
	    while(i<N){
	        int t=t2%mod;
	        t2=(t1+t2)%mod;
	        t1=t;
	        i++;
	    }
	    long long int ans=t2*t2;

	    return ans%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends