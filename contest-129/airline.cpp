//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	long long int MaximumPossibleCost(int n, int m,vector<vector<int>>routes){
		for(int i = 0; i < routes.size(); i++){
			routes[i][2] *= -1;
			routes[i][0]--;
			routes[i][1]--;
		}
		using ll = long long int;
		ll inf = 1e16;
		vector<ll>dis(n, inf);
		vector<ll>par(n+5, 0);
		dis[0] = 0;
		ll x = 0;
		for(int i = 0; i < n; i++){
			x = -1;
			for(int j = 0; j < routes.size(); j++){
					if(dis[routes[j][0]] == inf)continue;
					if(dis[routes[j][1]] > dis[routes[j][0]] + (ll)routes[j][2]){
						dis[routes[j][1]] = max(-inf, dis[routes[j][0]] + (ll)routes[j][2]);
						x = routes[j][1];
						par[routes[j][1]+1] = routes[j][0] + 1;
					}
			}
		}
		ll a = n;
		for(int i = 1; i <= n; i++)a = par[a];
		if(a != 0 or dis[n-1] == inf)return -1;
		return -1LL * dis[n-1];
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>routes(m, vector<int>(3,0));
		for(int i = 0; i < m; i++)
			for(int j = 0; j < 3; j++)
				cin >> routes[i][j];
		Solution obj;
		long long int ans = obj.MaximumPossibleCost(n,m,routes);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends