#User function Template for python3

class Solution:
    def fibbo(self, ans, k, n):
        if k >= n:
            return
        ans.append(ans[k - 1] + ans[k - 2])
        self.fibbo(ans, k + 1, n)

    def printFibb(self, n):
        ans = [1]
        if n == 1:
            return ans
        ans.append(1)
        self.fibbo(ans, 2, n)
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n=int(input())
        res = Solution().printFibb(n)
        for i in range (len(res)):
            print (res[i], end = " ") 
        print()
# } Driver Code Ends