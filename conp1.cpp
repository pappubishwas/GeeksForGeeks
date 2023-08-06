//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int len=s.size();
        int b=0,l=0,a=0,o=0,n=0;
        for (int i=0;i<len;i++)
        {
            if(s[i]=='b') b++;
            else if(s[i]=='l') l++;
            else if(s[i]=='o') o++;
            else if(s[i]=='n')n++;
        }
        l=l/2;
        o=o/2;
        vector<int> v;
        v.push_back(l);
        v.push_back(n);
        v.push_back(o);
        v.push_back(b);
        v.push_back(a);
        return *max_element(v.begin(), v.end());
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends