//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int backtracking(int arr[],int l,int n,vector<int>&v){

    if(l>=n){
        return 0;
    }
    int max1,max2;
    if(l+2<n && v[l+2]!=0){
        max1=v[l+2];
    }else
    max1=backtracking(arr,l+2,n,v);
    if(l+3<n && v[l+3]!=0)
        max2=v[l+3];
    else
    max2=backtracking(arr,l+3,n,v);
    
    max1=max1+arr[l];
    max2=max2+arr[l];
    int maximum=max(max1,max2);
    v[l]=maximum;
    return maximum;
    

}
// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        std::vector<int> v(n, 0);
        int max1,max2;
        max1=backtracking(arr,0,n,v);
        max2=backtracking(arr,1,n,v);
        return max(max1,max2);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends