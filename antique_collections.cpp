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
    int antiqueItems(int n, vector<int> &items, vector<int> &price) {
        // code here
        vector<int>mp(1010,100000);
        for(int i=0;i<n;i++){
            mp[items[i]]=min(mp[items[i]],price[i]);
        }
        int ans=0;
        for(int i=0;i<1010;i++){
            if(mp[i]!=100000) ans+=mp[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> items(n);
        Array::input(items,n);
        
        
        vector<int> price(n);
        Array::input(price,n);
        
        Solution obj;
        int res = obj.antiqueItems(n, items, price);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends