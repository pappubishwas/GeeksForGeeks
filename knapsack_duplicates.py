#User function Template for python3

class Solution:
    def knapSack(self, N, W, val, wt):
        # code here
        dp=[]
        dp.append(0)
        t=0
        for bagc in range(1,W+1):
            maxval=0
            for i in range(0,N):
                if wt[i]<=bagc:
                    rbagc=bagc-wt[i]
                    t=dp[rbagc]+val[i]
                if maxval<t:
                    maxval=t
            dp.append(maxval)
        return dp[W]    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, W = [int(x) for x in input().split()]
        val = input().split()
        for itr in range(N):
            val[itr] = int(val[itr])
        wt = input().split()
        for it in range(N):
            wt[it] = int(wt[it])
        
        ob = Solution()
        print(ob.knapSack(N, W, val, wt))
# } Driver Code Ends