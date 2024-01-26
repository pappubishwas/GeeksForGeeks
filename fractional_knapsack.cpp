//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        priority_queue<pair<double, int>> pq;  
        double res = 0;
        for (int i = 0; i < n; i++) {
            pq.push({(double)arr[i].value / arr[i].weight, arr[i].weight});
        }
        while (!pq.empty() && W > 0) { 
            auto p = pq.top();
            pq.pop();
            if (p.second < W) {
                res += (p.first * p.second);
                W -= p.second; 
            } else {
                res += (p.first * W);
                W = 0;
            }
        }
        return res;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends