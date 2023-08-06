//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:

    void deleteMid(stack<int>&st, int sizeOfStack)
    {
     vector<int> v;   
      while(!st.empty()){
      v.push_back(st.top());
      st.pop();
    }
    int n=v.size();
    if(n%2==0){
      int target=(n/2);
      for(int i=0;i<n;i++){
        if(i==target)continue;
        st.push(v[i]);
      }
    }else{
      int target=ceil(n/2);
      for(int i=0;i<n;i++){
        if(i==target)continue;
        st.push(v[i]);
      }
    }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends