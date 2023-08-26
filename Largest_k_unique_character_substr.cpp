//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int start = 0, end = 0, maxvalue = 0, findx = 0;
        char fc;
        set<char> st;
        unordered_map<char,int> frq;
        while (end < s.length())
        {
            frq[s[end]]++;
            st.insert(s[end]);
            if (st.size() > k)
            {
                maxvalue = max(maxvalue, (end - start));
                while (true)
                {
                    if(frq[s[start]]==1)
                    {
                        frq[s[start]]--;
                        fc=s[start];
                        start++;
                        break;
                    }else{
                        frq[s[start]]--;
                        start++;
                    }
                }
                
                auto it = st.find(fc);
                if (it != st.end())
                    st.erase(it);
            }
            end++;
        }
        if (st.size() != k)
            return -1;
        
        maxvalue = max(maxvalue, (end - start));
        return maxvalue;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends