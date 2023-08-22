//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxsum=0,count=0;
        vector<int> row;
        for(int i=0;i<n;i++){
            int sum=0,sum2=0;
            for(int j=0;j<n;j++){
                sum+=matrix[i][j];
                sum2+=matrix[j][i];
            }
            row.push_back(sum2);
            maxsum=max(maxsum,sum2);
            maxsum=max(maxsum,sum);
        }
        for(int i=0;i<n;i++){
            count+=abs(maxsum-row[i]);
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends