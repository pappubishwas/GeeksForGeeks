//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string str)
    {
       //Your code here
    pair<int, int> arr[256];
 
    for (int i = 0; str[i]; i++) {
        (arr[str[i]].first)++;
        arr[str[i]].second = i;
    }
    for (int i = 0; i<256; i++) {
        cout<<arr[i].first<<"  "<<arr[i].second<<endl;
    }
    
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
        if (arr[i].first == 1)
            res = min(res, arr[i].second);
            
    if(res==INT_MAX) return '$';
    else return str[res];
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends