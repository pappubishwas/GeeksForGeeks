//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int candyShop(int n, vector<int> &c) {
        // code here
        set<int> s(begin(c),end(c));
        int sum=0;
        for(auto &t:s) sum+=t;
        return sum;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> candies(n);
        Array::input(candies,n);
        
        Solution obj;
        int res = obj.candyShop(n, candies);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends