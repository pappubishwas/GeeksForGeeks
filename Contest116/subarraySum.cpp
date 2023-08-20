//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    long long maxSum(int N, vector<int> A)
    {
        // code here
        long long sum=0;
        // sort(A.begin(),A.end());
        int i=0,count=0;
        while (i<N-1)
        {
            if(A[i]<0)
            count++;
            else
            break;
            A[i]=abs(A[i]);
            i++;
        }
        // if(count%2==1 && i>1)
        // A[i-1]=-A[i-1];
        // sort(A.begin(),A.end());
        for ( i = 0; i < N;i++)
        {
            int l=0,r=0;
            long long tempsum=0;
            while (r<N)
            {
                if(r-l>i){
                    sum+=tempsum;
                    tempsum=tempsum+A[r]-A[l];
                    r++;
                    l++;
                }else{
                    tempsum+=A[r];
                    r++;
                }
            }
            sum+=tempsum;
        }
        

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
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution obj;
        cout<<obj.maxSum(N, A)<<endl;
    }
}  
// } Driver Code Ends