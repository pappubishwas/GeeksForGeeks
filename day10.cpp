//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int LongestRepeatingSubsequence(string str) {
        map<char, int> mp;
        int len = str.length();
        int c = 0,max=0, sum = 0;

        for (int i = 0; i < len; i++) {
            c = 0;
            map<char, int>::iterator it = mp.begin();
            while (it != mp.end()) {
                if (str[i] == it->first) {
                    it->second = it->second + 1;
                    c = 1;
                    break;
                }
                it++;
            }
            if (c == 0) {
                mp.insert({str[i], 1});
            }
        }

        map<char, int>::iterator it = mp.begin();
        while (it != mp.end()) {
            if(max<it->second) max=it->second;

            sum = sum + it->second / 2;
            it++;
        }
        if(sum>max-1) return sum;
        else
        return max-1;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends