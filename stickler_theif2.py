#User function Template for python3

class Solution:  
    
    #Function to find the maximum money the thief can get.
    def backtracking(self,a,l,n,dp):
        if l>=n:
            return 0
        if (l+2)<n and dp[l+2]!=0:
            max1=dp[l+2]
        else:
            max1=self.backtracking(a,l+2,n,dp)
        if (l+3)<n and dp[l+3]!=0:
            max2=dp[l+3]
        else:
            max2=self.backtracking(a,l+3,n,dp)
        
        maximum=max(max1+a[l],max2+a[l])
        dp[l]=maximum
        return maximum        
    def FindMaxSum(self,a, n):
        
        # code here
        #dp=[0]*n
        dp=[0 for _ in range(n)]   
        return max(self.backtracking(a,0,n,dp),self.backtracking(a,1,n,dp))
        
            


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
        n = int(input())
        a = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.FindMaxSum(a,n))
# } Driver Code Ends