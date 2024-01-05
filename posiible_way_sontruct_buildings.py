#User function Template for python3

class Solution:
	def TotalWays(self, N):
		# Code here
		mod=int(1e9) + 7
		t1=1
		t2=2
		i=1
		while i<N:
		    t=t2%mod
		    t2=(t1+t2)%mod
		    t1=t%mod
		    i+=1
		ans=(t2*t2)%mod    
		return int(ans)

#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.TotalWays(N)
		print(ans)
# } Driver Code Ends