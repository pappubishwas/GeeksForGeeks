#User function Template for python3


class Solution:
    def find(self, arr, n, x):
        
        # code here
        ans = [float('inf'), -1]
        self.binarySearch(arr,n,x,0,n-1,ans)
        if ans[1]==-1:
            ans[0]=-1
            ans[1]=-1
            return ans
        return ans
        
    def binarySearch(self,arr,n,x,l,h,ans):
        if l>h:
            return
        mid=(l+h)//2 
        if arr[mid]==x:
            ans[0]=min(ans[0],mid)
            ans[1]=max(ans[1],mid)
            self.binarySearch(arr,n,x,l,mid-1,ans)
            self.binarySearch(arr,n,x,mid+1,h,ans)
        elif arr[mid]>x:
            self.binarySearch(arr,n,x,l,mid-1,ans)
        else:
            self.binarySearch(arr,n,x,mid+1,h,ans)
        # code here


#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ob = Solution()
    ans=ob.find(arr,n,x)
    print(*ans)
# } Driver Code Ends