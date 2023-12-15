# User function Template for python3

import sys


class Solution:
    def nthPoint(self, n):
        # Code here
        curr = prev = 1
        i = 2
        mod = 1e9+7
        while i <= n:
            t = curr
            curr = (curr+prev) % mod
            prev = t
            i += 1
        return int(curr)


# {
 # Driver Code Starts
# Initial Template for Python 3

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.nthPoint(n)
        print(ans)
# } Driver Code Ends
