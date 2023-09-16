#User function Template for python3

class Solution:
    # Function to count the number of ways in which the frog can reach the top.
    
    def countWays(self, n, mod=1000000007):
        dp = [-1] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        if n >= 2:
            dp[2] = 2
        return self.countWaysHelper(n, dp, mod)
    
    def countWaysHelper(self, n, dp, mod):
        if n == 0 or n == 1:
            return 1
        if n == 2:
            return 2
        if dp[n] != -1:
            return dp[n]
    
        ways1 = self.countWaysHelper(n - 1, dp, mod) % mod
        ways2 = self.countWaysHelper(n - 2, dp, mod) % mod
        ways3 = self.countWaysHelper(n - 3, dp, mod) % mod
    
        dp[n] = (ways1 + ways2 + ways3) % mod
        return dp[n]


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
sys.setrecursionlimit(10**6)
# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        m = int(input())
        ob=Solution()
        print(ob.countWays(m))
# } Driver Code Ends