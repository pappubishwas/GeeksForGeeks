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
    int maxHappy(int n, vector<int> &bags, int m, vector<int> &rq) {
        // code here
        sort(begin(bags),end(bags));
        sort(begin(rq),end(rq));
        int i=0,j=0,res=0;
        while(i<n && j<m){
            if(bags[i]>=rq[j]){
                res++;
                j++;
                i++;
            }else
            i++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> bags(n);
        Array::input(bags,n);
        
        
        int m;
        scanf("%d",&m);
        
        
        vector<int> requirement(m);
        Array::input(requirement,m);
        
        Solution obj;
        int res = obj.maxHappy(n, bags, m, requirement);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends