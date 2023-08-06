//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
         // Freq map will store the frequency
    // of each element of the array
    unordered_map<int, int> freq;
 
    // Store the frequency of each
    // element from the array
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    unordered_set<int> uniqueFreq;
 
    // Check whether frequency of any
    // two or more elements are same
    // or not. If yes, return false
    for (auto& i : freq) {
        if (uniqueFreq.count(i.second))
            return false;
        else
            uniqueFreq.insert(i.second);
    }
 
    // Return true if each
    // frequency is unique
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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends