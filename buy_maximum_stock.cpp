//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        pq.push({-price[i],i+1});
        
        int count=0;
        while(!pq.empty()){
            int t1=-pq.top().first;
            int t2=pq.top().second;
            pq.pop();
            if(k>=t1){
                if(k>=t1*t2){
                    count+=t2;
                    k-=(t1*t2);
                }else{
                    count+=k/t1;
                    k-=(k/t1)*t1;
                }
            }else
            break;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends