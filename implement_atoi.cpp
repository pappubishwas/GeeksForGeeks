//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int t=1,i=0;
        if(s[0]=='-'){
            i=1;
            t=-1;
        }
        int n=s.size()-i;
        stack<int>st;
        while(i<s.size()){
            if(s[i]<'0' || s[i]>'9') return -1;
            else st.push(s[i]-'0');
            i++;
        }
        int num=0;
        for(int j=0;j<n;j++){
            int p=st.top();
            st.pop();
            num+=(pow(10,j)*p);
        }
        return t*num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends