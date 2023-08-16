//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int finddifference(string s1,string s2){
    int l=s1.length(),sum=0;
    for(int i=0;i<l;i++){
        int t=abs(s1[i]-s2[i]);
        sum+=t;
    }
    return sum;
  }
    int minimum_difference(int n, vector<string> &words) {
        // Code here.
        string st;
        int sum=1000000;
        for (int i=0;i<n;i++){
            st=words[i];
            for(int j=i+1;j<n;j++){
                int res=finddifference(st,words[j]);
                if(sum>res)
                sum=res;

                if(sum==0)
                break;
            }
            if(sum==0)
            break;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.minimum_difference(n, words) << endl;
    }
}

// } Driver Code Ends