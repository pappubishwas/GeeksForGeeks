#User function Template for python3
class Solution:
    def countStrings(self, n):
        if n == 1:
            return 2

        zero = 1
        one = 1
        i = 2
        mod = 1000000007

        while i < n:
            t = zero
            zero = (zero + one) % mod
            one = t % mod
            i += 1

        return (2 * zero % mod + one) % mod


#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        ob = Solution()
        ans = ob.countStrings( n)
        print(ans)
        tc=tc-1
# } Driver Code Ends