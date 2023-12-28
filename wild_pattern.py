#User function Template for python3

class Solution:
    def match(self, wild: str, pattern: str) -> bool:
        n = len(wild)
        m = len(pattern)
        
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        dp[n][m] = 1
        
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if wild[i] == '?':
                    dp[i][j] = dp[i + 1][j + 1]
                elif wild[i] == '*':
                    if i == n - 1:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = dp[i][j + 1] or dp[i + 1][j]
                else:
                    if wild[i] == pattern[j]:
                        dp[i][j] = dp[i + 1][j + 1]
                    else:
                        dp[i][j] = 0
        
        return dp[0][0]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        wild = input()
        pattern = input()
        
        ob = Solution()
        if(ob.match(wild, pattern)):
            print("Yes")
        else:
            print("No")
# } Driver Code Ends