#User function Template for python3
class Solution:
    mod = 1000000007

    def perfectSum(self, arr, n, sum):
        dp = [[0] * (sum + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            for j in range(sum + 1):
                if i == 0:
                    dp[i][j] = 1 if j == 0 else 0
                elif j < arr[i - 1]:
                    dp[i][j] = dp[i - 1][j]
                else:
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % self.mod

        return dp[n][sum] % self.mod


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,sum = input().split()
		n,sum = int(n),int(sum)
		arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.perfectSum(arr,n,sum)
		print(ans)

# } Driver Code Ends