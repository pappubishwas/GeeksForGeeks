
class Solution:
    def minDist(self, arr, n, x, y):
        f1,f2=-1,-1
        minx=10000000
        for i in range(n):
            if arr[i]==x:
                f1=i
            if arr[i]==y:
                f2=i
            
            if f1!=-1 and f2!=-1:
                minx=min(minx,abs(f1-f2))
        
        return -1 if minx==10000000 else minx        


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        x,y = list(map(int, input().strip().split()))
        print(Solution().minDist(arr, n, x, y))



# } Driver Code Ends