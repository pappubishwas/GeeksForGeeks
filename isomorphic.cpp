//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  bool areIsomorphic(string s1, string s2)
  {
      //Write Code Here
      unordered_map<char,char> mp;
      for(int i=0;i<s1.size();i++){
          if(mp.find(s1[i])!=mp.end()){
              if(mp[s1[i]]!=s2[i]) return false;
          }else 
          mp[s1[i]]=s2[i];
      }
      return true;
  }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        if(obj.areIsomorphic(s1,s2)) cout<<"1\n";
        else cout<<"0\n";
    }
}
// } Driver Code Ends