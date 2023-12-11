#User function Template for python3
# class Solution:
#     def maximumSumSubarray (self,K,Arr,N):
#         # code here 

class Solution:
    def maximumSumSubarray(self, K, arr, N):
        ans = 0
        curr_sum = 0
        l = 0
        for i in range(N):
            if i >= K:
                curr_sum -= arr[l]
                curr_sum += arr[i]
                l += 1
            else:
                curr_sum += arr[i]
            ans = max(ans, curr_sum)
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        N,K = input().split()
        N = int(N)
        K = int(K)
        Arr = list( map(int,input().strip().split(" ")))

        ob = Solution()
        print(ob.maximumSumSubarray(K,Arr,N))
# } Driver Code Ends