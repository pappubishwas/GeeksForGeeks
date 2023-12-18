#User function Template for python3

class Solution:
    def gameOfXor(self, N , A):
        # code here 
        if N%2==0:
            return 0
        res=A[0]
        i=2
        while i<N:
            res=res^A[i]
            i+=2
        return res    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        A=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.gameOfXor(N,A))
# } Driver Code Ends