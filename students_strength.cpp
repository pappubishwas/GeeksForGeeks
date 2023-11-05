//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

int diffSum(int n,int m,int arr[]);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i = 0;i<n;i++)cin>>arr[i];
        cout<<diffSum(n,m,arr);
        if(t)cout<<endl;
    }
}

// } Driver Code Ends
//User function Template for C++

int diffSum(int n,int m,int arr[])
{
    //write your code here
    sort(arr,arr+n);
    int suma=0,sumb=0;
    for(int i=0;i<m;i++)  suma=suma+arr[i];
    for(int i=n-m;i<n;i++) sumb=sumb+arr[i];
    int diff=sumb-suma;
    return diff;
}

//{ Driver Code Starts.

// } Driver Code Ends