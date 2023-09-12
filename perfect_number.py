#User function Template for python3
class Solution:
    def isPerfectNumber(self, n: int) -> int:
        if n == 1:
            return 0

        divisors_sum = 1
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                divisors_sum += i
                if i != n // i:
                    divisors_sum += n // i

        return 1 if divisors_sum == n else 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.isPerfectNumber(N))
# } Driver Code Ends