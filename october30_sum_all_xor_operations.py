#User function Template for python3

class Solution:
    def sumXOR (self, arr, n) : 
        #Complete the function
        sum=0
        for i in range(32):
            nz=0
            no=0
            for j in range(n):
                if arr[j]%2==0:
                    nz+=1
                else:
                    no+=1
                arr[j]//=2    
            sum+=(nz*no)*(1<<i)
        return sum    
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3



for _ in range(0,int(input())):
    
    n = int(input())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    res = ob.sumXOR(arr, n)
    print(res)


# } Driver Code Ends