//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public: 
    long long int largestPrimeFactor(int N){
       long long int factor=0,d=2;
       //int d=2;
        while (d*d<=N)
        {
            while(N%d==0){
            factor=d;
            N/=d;
            }
            d+=1;
        }
        if(N>1)
        factor=N;

        return factor;

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends