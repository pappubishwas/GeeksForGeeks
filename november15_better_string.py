#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

# class Solution:
#     def betterString(self, str1, str2):
        # Code here
        
class Solution:
    def betterString(self, str1, str2):
        a = self.count_sub(str1)
        b = self.count_sub(str2)
        return str1 if a >= b else str2
    
    def count_sub(self, s):
        mp = {}
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            dp[i] = 2 * dp[i - 1]
            if s[i - 1] in mp:
                dp[i] -= dp[mp[s[i - 1]]]
            mp[s[i - 1]] = i - 1

        return dp[n]        

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        str1 = input()
        str2 = input()
        ob = Solution()
        res = ob.betterString(str1, str2)
        print(res)
# } Driver Code Ends