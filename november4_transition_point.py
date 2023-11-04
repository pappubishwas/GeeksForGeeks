class Solution:
    def transitionPoint(self, arr, n): 
        # Code here
        ind,l,r=-1,0,n-1
        while l<=r:
            m=(l+r)//2
            if arr[m]==1:
                ind=m
                r=m-1
            else:
                l=m+1
        return ind        


#{ 
 # Driver Code Starts
#driver code
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.transitionPoint(arr, n))

# } Driver Code Ends