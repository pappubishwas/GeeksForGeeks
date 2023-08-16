#User function Template for python3

class Solution:
    def largestPrimeFactor (self, N):
        # code here
        factor=0
        d=2
        while d*d<=N:
            while N%d==0:
                factor=max(factor,d)
                N//=d
            d+=1
        if N>1:
            factor=max(factor,N)
        return factor    
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
       

        ob = Solution()
        print(ob.largestPrimeFactor(N))
# } Driver Code Ends