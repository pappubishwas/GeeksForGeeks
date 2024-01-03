#User function Template for python3

class Solution:
    def maxSumWithK(self, a, n, k):
        dp = [0] * (n + 1)
        
        for i in range(n - 1, -1, -1):
            dp[i] = a[i] + dp[i + 1]
            dp[i] = max(dp[i], 0)
        
        ans = float('-inf')
        
        cur_sum = sum(a[:k])
        
        for i in range(k, n):
            total_sum = cur_sum + dp[i]
            ans = max(ans, total_sum)
            
            cur_sum += a[i]
            cur_sum -= a[i - k]
        
        return max(ans, cur_sum)

    
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())
        
        ob = Solution()
        print(ob.maxSumWithK(a, n, k))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends