#User function Template for python3

class Solution:
    def countSubarrays(self, a,n,L,R): 
        # Complete the function
        btlr,ans,lessl=0,0,0
        for i in range(n):
            if a[i]<L:
                ans+=btlr
                lessl+=1
            elif a[i]>R:
                btlr,lessl=0,0
            else:
                ans+=btlr+lessl+1
                btlr+=lessl+1
                lessl=0
        return ans        


#{ 
 # Driver Code Starts
#Initial Template for Python 3



for _ in range(0,int(input())):
    n,l,r = map(int, input().strip().split())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    v = ob.countSubarrays(arr, n, l, r)
    print(v)
    
# } Driver Code Ends