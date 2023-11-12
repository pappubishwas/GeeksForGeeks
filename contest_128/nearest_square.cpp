//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  long long nearestSquare(long long n)
  {
      //Write Code Here
      long long int prev,next,i=1,t=sqrt(n);
      prev=pow(t,2);
      next=pow(t+1,2);
      if((abs(n-prev))<(abs(n-next))) return prev;
      else return next;
      
  }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        Solution obj;
        cout<<obj.nearestSquare(n)<<endl;
    }
}
// } Driver Code Ends