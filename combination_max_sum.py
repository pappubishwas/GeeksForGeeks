#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
import heapq
class Solution:
    def maxCombinations(self, N, K, A, B):
        # Code here
        A.sort()
        B.sort()
        ans=[]
        pq=[]
        for i in range(N):
            pq.append([-A[i]-B[N-1],N-1])
            
        heapq.heapify(pq)    
        while pq and K>0:
            sum,ind=heapq.heappop(pq)
            ans.append(-sum)
            if ind-1>=0:
                heapq.heappush(pq,[sum+B[ind]-B[ind-1],ind-1])
            K-=1
        return ans        

        

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, K = list(map(int, input().split()))
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        ob = Solution()
        res = ob.maxCombinations(N, K, A, B)
        for val in res:
            print(val, end =' ')
        print()
# } Driver Code Ends