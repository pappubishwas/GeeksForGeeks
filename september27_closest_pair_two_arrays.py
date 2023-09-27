#User function Template for python3
import sys
class Solution:
    def printClosest (self,arr, brr, n, m, x) : 
        #code here
        i,j,ans=0,m-1,sys.maxsize
        ls=[0,0]
        while i<n and j>=0:
            sum=arr[i]+brr[j]
            res=abs(sum-x)
            if(ans>res):
                ans=res
                ls[0]=arr[i]
                ls[1]=brr[j]
            elif sum<x:
                i+=1
            else:
                j-=1
                    
        return ls


#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().strip().split()))
    brr = list(map(int, input().strip().split()))
    x = int(input())
    ob = Solution()
    ans = ob.printClosest(arr, brr, n, m, x)
    print(abs(ans[0]+ans[1] - x))
# } Driver Code Ends