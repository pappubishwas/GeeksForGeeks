#User function Template for python3
# class Solution:
# 	def longSubarrWthSumDivByK (self,arr,  n, K) : 
# 		#Complete the function
class Solution:
    def longSubarrWthSumDivByK(self, arr,n, k):
        # Complete the function
        n = len(arr)
        _sum = 0
        suffix = {0: -1}  # define the map.....(dictionary)
        
        ans = 0
        
        for i in range(n):
            _sum = (_sum + (arr[i] % k) + k) % k
            
            if _sum not in suffix:
                suffix[_sum] = i
            else:
                ans = max(ans, i - suffix[_sum])
        
        return ans
		




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

	for _ in range(0,int(input())):
		n, K = map(int ,input().split())
		arr = list(map(int,input().strip().split()))
		ob = Solution()
		res = ob.longSubarrWthSumDivByK(arr, n, K)
		print(res)




# } Driver Code Ends