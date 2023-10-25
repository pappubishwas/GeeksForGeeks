#User function Template for python3

# class Solution:
#     def palindromicPartition(self, string):
#         # code here
class Solution:
    def is_palindrome(self, s, i, j):
        while i <= j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def palindromicPartition(self, s):
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for gap in range(n):
            for row in range(n - gap):
                col = row + gap
                if self.is_palindrome(s, row, col):
                    dp[row][col] = 0
                else:
                    dp[row][col] = float('inf')
                    for k in range(row, col):
                        dp[row][col] = min(dp[row][col], 1 + dp[row][k] + dp[k + 1][col])
        return dp[0][n - 1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends