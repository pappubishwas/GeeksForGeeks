//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void findSubsequence(int a[], int k, int n, unordered_map<int, int> &mp)
    {
        int ans;
        if (k == n - 1){
            mp[a[k]]=1;
            return;
        }
            if(k>=n)
            return;
        if (mp[a[k]] != 0)
            return;
        // for (int i = k; i < n; i++)
        // {
            ans=0;
            int temp=a[k];
            for (int j = k + 1; j < n; j++)
            {

                if (temp< a[j])
                {
                    findSubsequence(a, j, n, mp);
                    temp=a[j];
                    ans +=1;
                }
            }
            mp[a[k]] = max(mp[a[k]], ans+1);
            while (k<n)
            {
                findSubsequence(a,k+1,n,mp);
                k++;
            }
            
        //}

        
        return;
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here
        int ans = 1;
        unordered_map<int, int> mp;
        findSubsequence(a,0,n,mp);
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
            if (ans < it->second)
                ans = it->second;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends