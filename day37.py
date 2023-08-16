
from math import factorial
class Solution:
    def findCatalan(self, n : int) -> int:
        # code here
        mod = int(1e9 + 7)
        return int((factorial(2 * n) // (factorial(n + 1) * factorial(n))) % mod)        




# Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        obj = Solution()
        res = obj.findCatalan(n)
        
        print(res)
        

# } Driver Code Ends