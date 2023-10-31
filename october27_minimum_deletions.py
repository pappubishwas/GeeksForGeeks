#User function Template for python3

# class Solution:
#     def minimumNumberOfDeletions(self,S):
#         # code here 
class Solution:
    def __init__(self):
        self.n = 0
        self.dp = [[0] * 1001 for _ in range(1001)]
        self.ch = [[''] * 1001 for _ in range(1001)]

    def printlcs(self, s, i, j):
        if i == 0 or j == 0:
            return 0
        if self.ch[i][j] == 'c':
            return 1 + self.printlcs(s, i - 1, j - 1)
        elif self.ch[i][j] == 'u':
            return self.printlcs(s, i - 1, j)
        else:
            return self.printlcs(s, i, j - 1)

    def lcs(self, s1, s2):
        self.n = len(s1)
        for i in range(1, self.n + 1):
            for j in range(1, self.n + 1):
                if s1[i - 1] == s2[j - 1]:
                    self.dp[i][j] = self.dp[i - 1][j - 1] + 1
                    self.ch[i][j] = 'c'
                elif self.dp[i - 1][j] >= self.dp[i][j - 1]:
                    self.dp[i][j] = self.dp[i - 1][j]
                    self.ch[i][j] = 'u'
                else:
                    self.dp[i][j] = self.dp[i][j - 1]
                    self.ch[i][j] = 'l'

    def minimumNumberOfDeletions(self, s1):
        s2 = s1[::-1]
        self.lcs(s1, s2)
        return self.n - self.printlcs(s1, self.n, self.n)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=input()

        ob = Solution()
        print(ob.minimumNumberOfDeletions(S))
# } Driver Code Ends