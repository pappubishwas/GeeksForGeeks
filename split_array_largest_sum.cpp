//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isvalid(int a[],long long int mid,int n,int k){
        int currSum=0,left=k,i=0;
        while(i<n && left>0){
            currSum=0;
            left--;
            while(left<n-i && i<n){
                if(a[i]>mid) return false;
                currSum+=a[i];
                if(currSum>mid){
                    break;
                }
                i++;
            }
        }
        if(i<n) return false;
        return true;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        long long int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        long long int l=0,h=sum,ans;
        while(l<=h){
            long long int mid=(l+h)/2;
            if(isvalid(arr,mid,N,K)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends