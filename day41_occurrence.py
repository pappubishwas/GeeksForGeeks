#User function Template for python3
class Solution:
    def recursion(self, arr, dp, start, end, x):
        if start > end or x < arr[start] or x > arr[end]:
            return
        med = (start + end) // 2
        if x == arr[med]:
            dp[0] += 1
            self.recursion(arr, dp, start, med - 1, x)
            self.recursion(arr, dp, med + 1, end, x)
        elif x > arr[med]:
            self.recursion(arr, dp, med + 1, end, x)
        else:
            self.recursion(arr, dp, start, med - 1, x)

    def count(self, arr, n, x):
        dp = [0]
        self.recursion(arr, dp, 0, n - 1, x)
        return dp[0]

		

#{ 
 # Driver Code Starts
#Initial Template for Python 3




if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, x = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.count(arr, n, x)
        print(ans)
        tc -= 1

# } Driver Code Ends