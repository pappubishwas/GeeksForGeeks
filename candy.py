#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

# class Solution:
#     def minCandy(self, N, ratings):
#         # Code here
        
class Solution:
    def minCandy(self, N, ra):
        ans = [1] * N
        
        for i in range(1, N):
            if ra[i] > ra[i - 1]:
                ans[i] = ans[i - 1] + 1
        
        for i in range(N - 2, -1, -1):
            if ra[i] > ra[i + 1]:
                ans[i] = max(ans[i + 1] + 1, ans[i])
        
        return sum(ans)
        

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N = int(input())
        ratings = list(map(int, input().split()))
        ob = Solution()
        res = ob.minCandy(N, ratings)
        print(res)
# } Driver Code Ends