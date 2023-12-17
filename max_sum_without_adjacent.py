# User function Template for python3
class Solution:

    def findMaxSum(self, arr, n):
        # code here
        curr, prev = arr[0], 0
        for i in range(1, n):
            if prev+arr[i] > curr:
                prev, curr = curr, prev+arr[i]
            else:
                prev = curr

        return max(curr, prev)


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaxSum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
