//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            int len=0;
            int m=pat.size();
            int i=1;
            vector<int> lps(m);
            while (i<m){
                if(pat[i]==pat[len]){
                    lps[i]=len+1;
                    len++;
                    i++;
                }else{
                    if(len!=0)
                    len=lps[len-1];
                    else{
                        lps[i]=0;
                        i+=1;
                    }
                }
            }
            
            int n=txt.size();
            vector<int> ans;
            i=0;
            int j=0;
            while (i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }else{
                    if(j!=0)
                    j=lps[j-1];
                    else i++;
                }
                if(j==m){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
            }
            if(ans.empty()) return {-1};
            return ans;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends