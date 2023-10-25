# User function Template for python3
class Solution:
    def maxSumIS(self, arr, n):
        # code here
        ans = []
        ans.append(arr[0])
        res = arr[0]
        for i in range(1, n):
            ans.append(arr[i])
            for j in range(0, i):
                if arr[j] < arr[i] and ans[i] < ans[j]+arr[i]:
                    ans[i] = ans[j]+arr[i]
            res = max(res, ans[i])
        return res

# {
# Driver Code Starts
# Initial Template for Python 3

				
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.maxSumIS(Arr, n)
        print(ans)

# } Driver Code Ends
