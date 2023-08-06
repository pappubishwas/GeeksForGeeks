//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int m,int n,int t)
    {
 		// Your code goes here.
 			// Your code goes here.
        int i, k = 0, l = 0,ans=10,p=t;
 
    while (k < m && l < n && p>0) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n && p>0; ++i) {
            if(p==1){
                 ans=a[k][i];
            
           }
           p--;
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m && p>0; ++i) {
            
            if(p==1){
                 ans=a[i][n-1];
            
           }
           p--;
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l && p>0 ; --i) {
                cout << a[m - 1][i] << " ";
                if(p==1){
                 ans=a[m-1][i];
                }
           
           p--;
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k && p>0; --i) {
                if(p==1){
                 ans=a[i][l];
                
           }
           p--;
            }
            l++;
        }
    }
    return ans;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends