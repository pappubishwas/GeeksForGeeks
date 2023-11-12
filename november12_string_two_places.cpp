//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string s1, string s2)
    {
        // Your code here
        if (s1.size() != s2.size())
            return false;

        int n = s1.size();
        if ((s1.substr(0, 2) == s2.substr(n - 2, 2)) && (s1.substr(2, n - 2) == s2.substr(0, n - 2)))
            return true;

        if ((s1.substr(0, n - 2) == s2.substr(2, n - 2)) && (s1[n - 2] == s2[0] && s1[n - 1] == s2[1]))
            return true;

        return false;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends