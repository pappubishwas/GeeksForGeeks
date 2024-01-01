#User function Template for python3

from collections import defaultdict

class Solution:
    def canPair(self, nums, k):
        f = defaultdict(int)
        
        for num in nums:
            cur = num % k
            need = (k - cur) % k
            
            if need in f and f[need] > 0:
                f[need] -= 1
                if f[need] == 0:
                    del f[need]
            else:
                f[cur] += 1
        
        return len(f) == 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, k = input().split()
		n = int(n)
		k = int(k)
		nums = list(map(int, input().split()))
		ob = Solution()
		ans = ob.canPair(nums, k)
		if(ans):
			print("True")
		else:
			print("False")
# } Driver Code Ends