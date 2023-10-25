#User function Template for python3

#   >> PYTHON CODE <<

class Solution:
    def numberOfPaths(self, M, N):
        mod = int(1e9 + 7)
        
        n = M + N - 2
        r = M - 1
        ans = 1

        # Calculate (n choose r) % mod
        for i in range(1, r + 1):
            ans = (ans * (n - i + 1)) % mod
            ans = (ans * pow(i, mod - 2, mod)) % mod  # Calculate the modular inverse and use it for division

        return int(ans)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

        

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        M, N = map(int, input().split())
        ans = ob.numberOfPaths(M, N)
        print(ans)




# } Driver Code Ends