#User function Template for python3

class Solution:
    def isvalid(self,arr,mid,n,k):
        left=k
        i=0
        while i<n and left>0:
            left-=1
            currsum=0
            while i<n and left<n-i:
                if arr[i]>mid:
                    return False
                currsum+=arr[i]
                if currsum>mid:
                    break
                i+=1
        if i<n:
            return False
        return True    
    def splitArray(self, arr, N, K):
        # code here 
        l=0
        h=sum(arr)
        ans=0
        while l<=h:
            mid=int((l+h)/2)
            if self.isvalid(arr,mid,N,K):
                ans=mid
                h=mid-1
            else:
                l=mid+1
        return ans        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N,K=map(int,input().split())
        arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.splitArray(arr,N,K))
# } Driver Code Ends