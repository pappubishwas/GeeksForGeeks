//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std ; 


// } Driver Code Ends
class Solution {
	public:
	int minOperations(vector<int> a, int n) {
	    // Code here
	    int mx=*max_element(a.begin(),a.end());
	    int c=0,cs=0,t=0;
	    for(int i=0;i<n;i++){
	        if(mx==a[i]){
	            t++;
	            c++;
	        }else{
	            cs=max(cs,t);
	            t=0;
	        }
	    }
	    cs=max(cs,t);
	    return c-cs;
	}
};

//{ Driver Code Starts.


int main() {
  int t ; 
  cin >> t ;
  while(t--) {
  	int n ;
  	cin >> n ; 
  	vector<int> a(n) ;
  	for(int i = 0 ; i < n ; ++i)
  		cin >> a[i] ; 
 
  	Solution ob ;
  	cout << ob.minOperations(a,n) << "\n"; 
   }
}



// } Driver Code Ends