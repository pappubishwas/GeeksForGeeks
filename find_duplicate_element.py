class Solution:
    def duplicates(self, arr, n):
        mp = {}
        for i in range(0, n):
            if arr[i] in mp:
                mp[arr[i]] += 1
            else:
                mp[arr[i]] = 1
        ans = []
        for i in range(0, n):
            if mp.get(i, 0) > 1:  # Use mp.get(i, 0) to safely retrieve the count
                ans.append(i)
        if not ans:
            ans.append(-1)
        return ans


# {
 # Driver Code Starts
if (__name__ == '__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i, end=" ")
        print()


# } Driver Code Ends
