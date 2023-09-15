# User function Template for Python3

class Solution:
    def subset_sum_helper(self, i, total_sum, arr, dp):
        if total_sum == 0:
            return True
        if i >= len(arr) or total_sum < 0:
            return False

        if dp[i][total_sum] != -1:
            return dp[i][total_sum]

        pick = self.subset_sum_helper(i + 1, total_sum - arr[i], arr, dp)
        not_pick = self.subset_sum_helper(i + 1, total_sum, arr, dp)

        dp[i][total_sum] = pick or not_pick
        return dp[i][total_sum]

    def equalPartition(self, n, arr):
        total_sum = sum(arr)

        if total_sum % 2 != 0:
            return 0  # Return 0 for "NO"

        target_sum = total_sum // 2
        dp = [[-1 for _ in range(target_sum + 1)] for _ in range(n)]

        result = self.subset_sum_helper(0, target_sum, arr, dp)

        return 1 if result else 0
#{ 
 # Driver Code Starts
# Initial Template for Python3

import sys
input = sys.stdin.readline
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for it in range(N):
            arr[it] = int(arr[it])
        
        ob = Solution()
        if (ob.equalPartition(N, arr) == 1):
            print("YES")
        else:
            print("NO")
# } Driver Code Ends